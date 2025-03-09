// 166E 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[1] = 0;
    if (n > 1)
        dp[2] = 3;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3) % MOD;
    cout << dp[n] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
