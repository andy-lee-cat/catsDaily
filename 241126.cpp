// 1195C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<long long>> h(2, vector<long long>(n));
    for (int i = 0; i < n; i++) 
        cin >> h[0][i];
    for (int i = 0; i < n; i++) 
        cin >> h[1][i];
    vector<vector<long long>> dp(3, vector<long long>(n, 0));
    dp[0][0] = h[0][0];
    dp[1][0] = h[1][0];
    dp[2][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + h[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + h[1][i];
        dp[2][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
