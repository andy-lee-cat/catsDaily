// 474D 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 1e5 + 5;
vector<vector<long long>> dp;
vector<long long> res;
const int MOD = 1e9 + 7;
const int R = 0;
const int W = 1;
int k;

void init() {
    dp.resize(MAXN, vector<long long>(2, 0));
    // XXXXXXXXXR
    // XXXXXXXXXW
    dp[0][R] = 0;
    dp[0][W] = 1;
    for (int i = 1; i < MAXN; i++) {
        dp[i][R] = dp[i - 1][W] + dp[i - 1][R];
        dp[i][R] %= MOD;
        if (i >= k) {
            dp[i][W] = dp[i - k][R] + dp[i - k][W];
            dp[i][W] %= MOD;
        }
    }
    res.resize(MAXN, 0);
    for (int i = 1; i < MAXN; i++) {
        res[i] = res[i - 1] + dp[i - 1][R] + dp[i - 1][W];
        res[i] %= MOD;
        // cout << i << " " << dp[i][R] << ' ' << dp[i][W] << endl;
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << (res[b + 1] - res[a] + MOD) % MOD << '\n';
}

int main() {
    int t = 1;
    cin >> t >> k;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
