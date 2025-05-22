// 607B 1900
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> c;
    c.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != c.back()) {
            c.push_back(a[i]);
        }
    }

    // 不能用预处理后的
    c = a;
    n = c.size();
    vector<vector<int>> dp(n, vector<int>(n, 1000));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    // 这题1 1 2 1输出 2的
    /*
        dp[i][j] = 0, i > j
        dp[i][j] = 1, i == j
        dp[i][j] = min(
            dp[i][j-1] + 1,
            dp[i+1][j] + 1, 
            dp[i+1][j-1] (if c[i] == c[j])
        )
    */
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = 1; k <= len / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[i][i + k - 1] + dp[i + k][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[j - k + 1][j]);
            }
            if (c[i] == c[j]) {
                if (len == 2) dp[i][j] = 1;
                else dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
