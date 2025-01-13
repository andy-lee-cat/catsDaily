// 1234D 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<set<int>> pos(26);
    for (int i = 0; i < s.length(); i++) {
        pos[s[i] - 'a'].insert(i);
    }
    auto query = [&](int l, int r) {
        l--, r--;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            auto it = pos[i].lower_bound(l);
            if (it != pos[i].end() && *it <= r) {
                cnt++;
            }
        }
        return cnt;
    };
    auto update = [&](int p, char c) {
        p--;
        int old_char = s[p] - 'a';
        int new_char = c - 'a';
        s[p] = c;
        pos[old_char].erase(p);
        pos[new_char].insert(p); 
    };

    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            char c;
            cin >> p >> c;
            update(p, c);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
