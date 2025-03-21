// 467C 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + p[i];
    // p[i] + ... p[j] = sum[j + 1] - sum[i]
    auto Sum = [&](int l, int r) -> long long {
        return sum[r + 1] - sum[l];
    };
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    // dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1])
    // dp[i][0] = 0
    // dp[0][j] = 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(
                dp[i - 1][j],
                i >= m ? dp[i - m][j - 1] + Sum(i - m, i - 1) : 0ll
            );
        }
    }
    cout << dp[n][k] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
