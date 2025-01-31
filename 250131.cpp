// 26B 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    int cnt = 0;
    for (char c : s) {
        if (c == '(')
            cnt++;
        else if (cnt > 0) {
            cnt--;
            res += 2;
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
