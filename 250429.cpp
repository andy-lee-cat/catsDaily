// 349B 1700
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int v;
    cin >> v;
    vector<int> a(10);
    a[0] = INT_MAX;
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
    }
    vector<int> dp(v + 1);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j < 10; j++) {
            if (i - a[j] >= 0) {
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    string res = "";
    int len = dp[v];
    while (len--) {
        for (int i = 9; i >= 1; i--) {
            if (v - a[i] >= 0 && dp[v] == dp[v - a[i]] + 1) {
                res += char(i + '0');
                v -= a[i];
                break;
            }
        }
    }
    cout << (res.length() == 0 ? "-1" : res) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
