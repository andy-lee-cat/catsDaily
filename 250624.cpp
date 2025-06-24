// 1886C 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
using namespace std;

struct Node {
    int idxl, idxr;
    Node *l, *r;
    Node(int idxl, int idxr, Node *l = nullptr, Node *r = nullptr) 
        : idxl(idxl), idxr(idxr), l(l), r(r) {}
};

void solve2() {
    string s;
    long long pos;
    cin >> s >> pos;
    pos--;
    vector<char> stk;
    int curlen = s.length();
    s += char('a' - 1);
    bool ok = pos < curlen;
    for (char c : s) {
        while (!ok && !stk.empty() && stk.back() > c) {
            stk.pop_back();
            pos -= curlen;
            curlen--;
            if (pos < curlen)
                ok = true;
        }
        stk.push_back(c);
    } 
    cout << stk[pos];
}

void solve() {
    // case1: s[0] > s[1]: remove s[0]
    // case2: s[0] <= s[1] <= s[2] ... > s[k]: remove s[k-1]
    // case3: all small: s[0] <= ... s[n-1]: remove last
    // case3 => case2
    string s;
    cin >> s;
    int n = s.length();
    long long pos;
    cin >> pos;
    int loop = 0;
    int now = n;
    while (pos > now) {
        loop++;
        pos -= now;
        now--;
    }
    pos -= 1;
    if (loop == 0) {
        cout << s[pos];
        return;
    }
    // dec s by loops elements, then choose s[pos]
    s += char('a' - 1);
    vector<char> stk;
    int idx = 0;
    for (char c : s) {
        if (stk.empty() || stk.back() <= c) {
            stk.push_back(c);
        } else {
            while (!stk.empty() && stk.back() > c) {
                stk.pop_back();
                loop--;
                if (loop == 0) {
                    if (pos < stk.size()) {
                        cout << stk[pos];
                    } else {
                        pos -= stk.size();
                        cout << s[idx + pos];
                    }
                    return; 
                }
            }
            stk.push_back(c);
        }
        idx++;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve2();
    }
    cout << '\n';
    return 0;
}
