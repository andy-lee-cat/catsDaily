// 1324E 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(h + 1));
    auto check = [&](int x) -> int {
        x %= h;
        return x >= l && x <= r ? 1 : 0;
    };
    /*
        dp[i][j] = max(
            dp[i + 1][(j + a[i]) % h] + check(j + a[i]),
            dp[i + 1][(j + a[i] - 1) % h] + check(j + a[i] - 1) 
        )
        dp[n][?] = 0
    */
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < h; j++) {
            dp[i][j] = max(
                dp[i + 1][(j + a[i]) % h] + check(j + a[i]),
                dp[i + 1][(j + a[i] - 1) % h] + check(j + a[i] - 1)
            );
        }
    }
    cout << dp[0][0] << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
