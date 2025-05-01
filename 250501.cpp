// 676C 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = n + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        int ca = 0, cb = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == 'a') ca++;
            else cb++;
        }
        int idx = m - 1;
        bool flag = false;
        while (idx < n) {
            if (ca <= k || cb <= k) {
                flag = true;
                break;
            }
            if (s[idx - m + 1] == 'a') ca--;
            else cb--;
            idx++;
            if (idx == n) break;
            if (s[idx] == 'a') ca++;
            else cb++;
        }
        if (flag) l = m + 1;
        else r = m;
    }
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
