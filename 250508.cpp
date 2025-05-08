// 1389C 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int res = 1;
    vector<int> cnts(10);
    for (char c : s) 
        cnts[c - '0']++;
    for (int i = 0; i < 10; i++)
        res = max(res, cnts[i]);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) continue;
            int idx = 0;
            int len = 0;
            while (idx < n) {
                while (idx < n && s[idx] != '0' + i) {
                    idx++;
                }
                if (idx < n) len++;
                while (idx < n && s[idx] != '0' + j) {
                    idx++;
                }
                if (idx < n) len++;
            }
            res = max(res, len % 2 == 0 ? len : len - 1);
        }
    }
    cout << n - res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
