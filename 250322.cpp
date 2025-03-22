// 343B 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

void solve() {
    string s;
    cin >> s;
    stack<char> stk;
    for (char c : s) {
        if (stk.empty() || stk.top() != c) {
            stk.push(c);
        } else {
            stk.pop();
        }
    }
    if (stk.empty()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
