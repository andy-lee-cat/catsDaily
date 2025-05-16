#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1000000007

long long add(long long x, long long y) {
    return (x + y) % MOD;
}

long long mul(long long x, long long y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

vector<vector<long long>> dp;
vector<vector<long long>> prefix;

void init(int n, int m) {
    dp = vector<vector<long long>>(m + 1, vector<long long>(n + 1));
    prefix = vector<vector<long long>>(m + 1, vector<long long>(n + 1));
    // dp[len][range] = dp[len-1][0...range]
    // dp[1][.] = 1, dp[1][0] = 0
    for (int j = 1; j <= n; j++)
        dp[1][j] = 1;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] = add(dp[i][j], dp[i - 1][k]);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    init(n, m);
    // 从n个数里选出r=2m个构成非递减数列
    // 选出了r个数，n-1个挡板，共n+r-1个位置
    // 结果是C(n+r-1,r) = C(n+r-1,n-1)
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // a0 = i, b_(n-1)=j
            res = add(res, mul(
                dp[m][i],
                dp[m][n-j+1]
            ));
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
