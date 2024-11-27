// 431c 1600
#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000007
using namespace std;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    /*
    dp[n][1] = dp[n - 1][1] + ... + dp[max(0, n - k)][1] + dp[n - d][0]
    dp[n][0] = dp[n - 1][0] + ... + dp[max(0, n - k)][0] 
    dp[0][0] = 1
    ask dp[n][0]
    */
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= max(0, i - k); j--) {
            if (j <= i - d)
                dp[i][1] += dp[j][0];
            else
                dp[i][1] += dp[j][1];
            dp[i][1] %= MOD;
            dp[i][0] += dp[j][0];
            dp[i][0] %= MOD;
        }
        // cout << "dp[" << i << "][0] = " << dp[i][0] << " dp[" << i << "][1] = " << dp[i][1] << '\n';
    }
    cout << dp[n][1] << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
