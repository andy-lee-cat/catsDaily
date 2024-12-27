// 414B 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    /*
    left k + 1 places
    dp[k][nownum]
    dp[0][x] = 1
    dp[i][j] = {
        dp[i+1][j / 2] + dp[i+1][j / 3]...
    }
    */
    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
    const int MOD = (int)1e9 + 7;
    for (int j = 1; j <= n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k * j <= n; k++) {
                dp[i][j] += dp[i - 1][k * j];
                dp[i][j] %= MOD;
            }
        }
    }
    // cout << *dp[k].begin() << '\n';
    cout << dp[k][1] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
