// 1881E 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<int> dp(n); 
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int idx = i - a[i] - 1;
        int last;
        if (idx == -1) last = 0;
        else if (idx < -1) last = INT_MAX;
        else last = dp[idx];
        dp[i] = min(last, 1 + dp[i - 1]);
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
