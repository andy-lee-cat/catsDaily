// 580D 1800
// if (((mask >> now) & 1) == 0) 
// 这句没加括号，写的(mask >> now) & 1 == 0
// 我就说怎么调试工具自动跳过这句了，断点也加不上
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<unordered_map<int, int>> rules(n);
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        rules[x - 1][y - 1] = c;
    }
    long long res = 0;
    vector<vector<long long>> dp(1 << n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = a[i];
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int now = 0; now < n; now++) {
            if (((mask >> now) & 1) == 0) 
                continue;
             
            for (int last = 0; last < n; last++) {
                if (last == now || ((mask >> last) & 1) == 0) continue;
                dp[mask][now] = max(
                    dp[mask][now],
                    dp[mask ^ (1 << now)][last] + a[now] + rules[last][now]
                );
            }
        }
        if (__builtin_popcount(mask) == m) 
            for (int i = 0; i < n; i++)
                if (dp[mask][i] > res)
                    res = max(res, dp[mask][i]);
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
