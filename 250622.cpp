// 1974E 1800
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int m;
    long long x;
    cin >> m >> x;
    vector<long long> c(m);
    vector<int> h(m);
    for (int i = 0; i < m; i++)
        cin >> c[i] >> h[i];
    
    int H = accumulate(h.begin(), h.end(), 0) + 2; 
    long long MAX = 1e18;
    vector<vector<long long>> dp(m + 1, vector<long long>(H, MAX));
    /*
    dp[i][j]: 第i个月开始，要达到j的幸福度，需要的最小本金
    dp[i][j] = min(dp[i + 1][j - h[i]] + c[i] - x, dp[i + 1][j] - x)

    dp[m-1][0] = 0;
    dp[m-1][1] ... dp[m-1][h[m-1]] = c[m-1];
    dp[m-1][h[m-1]+1] ... dp[m-1][H-1] = MAX;
    
    求: argmax j, dp[0][j] = 0
    */
    dp[m - 1][0] = 0;
    for (int j = 1; j <= h[m - 1]; j++)
        dp[m - 1][j] = c[m - 1];
    for (int j = h[m - 1] + 1; j < H; j++)
        dp[m - 1][j] = MAX;
    for (int i = m - 2; i >= 0; i--) {
        for (int j = H - 1; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j] - x;
            if (j != H - 1) { 
                dp[i][j] = min(dp[i][j], dp[i][j + 1]); // 拖一天
            }
            if (j >= h[i]) {
                dp[i][j] = min(dp[i][j], 
                    max(dp[i + 1][j - h[i]] + c[i] - x, c[i]));
                // 当天就买，至少有 c[i] 的本金
            }
            dp[i][j] = max(dp[i][j], 0LL);
        }
    }
    for (int j = 0; j < H; j++) {
        if (dp[0][j] > 0) {
            cout << j - 1 << '\n';
            return;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
