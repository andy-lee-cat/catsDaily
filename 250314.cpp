// 118D 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD (int)(1e8)

void solve() {
    int n0, n1, k0, k1;
    cin >> n0 >> n1 >> k0 >> k1;
    /*
        dp[0][i][j] = last 1, put 0, left i * 0, j * 1
        dp[1][i][j] = last 0, put 1, left i * 0, j * 1
        
        dp[0][i][j] = 0 if i == 0 && j != 0
        dp[0][i][j] = dp[1][i - 1][j] + dp[1][i - 2][j] + ... 
                        dp[0][i - k0][j]

        dp[0|1][0][0] = 1
    */
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n0 + 1, vector<int>(n1 + 1, -1)));
    dp[0][0][0] = dp[1][0][0] = 1;
    auto get = [&](auto &&self, int i, int j, int k) -> int {
        if (i < 0 || j < 0) return 0;
        if (k == 0 && i == 0 && j != 0) return 0;
        if (k == 1 && j == 0 && i != 0) return 0;
        if (dp[k][i][j] != -1) return dp[k][i][j];
        long long res = 0;
        if (k == 0) {
            for (int l = 1; l <= min(i, k0); l++) {
                res += self(self, i - l, j, 1);
                res %= MOD;
            }
            dp[k][i][j] = res;
        } else {
            for (int l = 1; l <= min(j, k1); l++) {
                res += self(self, i, j - l, 0);
                res %= MOD;
            }
            dp[k][i][j] = res;
        }
        return dp[k][i][j];
    };

    long long ans = 0;
    ans = get(get, n0, n1, 0) + get(get, n0, n1, 1);
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
