// 1528A 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    for (int i = 0; i < n; i++) 
        cin >> lr[i].first >> lr[i].second;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    auto dfs = [&](auto &&self, int v, int p) -> void {
        long long left = 0, right = 0;
        for (int u : edges[v]) {
            if (u == p) continue;
            self(self, u, v);
            left += max(
                dp[u][0] + abs(lr[u].first - lr[v].first),
                dp[u][1] + abs(lr[u].second - lr[v].first)
            );
            right += max(
                dp[u][0] + abs(lr[u].first - lr[v].second),
                dp[u][1] + abs(lr[u].second - lr[v].second)
            );
        }
        dp[v][0] = left;
        dp[v][1] = right;
    };

    dfs(dfs, 0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
