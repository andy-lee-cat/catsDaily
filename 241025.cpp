// 161d 1800
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long

void dfs(vector<vector<int>>& g, vector<vector<int>>& dp, int now, int par, int k, int& res) {
    dp[now][0] = 0;
    dp[now][1] = 1;
    for (int next : g[now]) {
        if (next == par) continue;
        dfs(g, dp, next, now, k, res);
    }
    for (int i = 2; i <= k; i++) {
        for (int next : g[now]) {
            if (next == par) continue;
            dp[now][i] += dp[next][i - 1];
        } 
    }
    int add = 0;
    for (int next : g[now]) {
        if (next == par) continue;
        for (int i = 1; i <= k - 2; i++) {
            add += dp[next][i] * (dp[now][k - i] - dp[next][k - i - 1]);
        }
    }
    res += add / 2;
    res += dp[now][k];
}

void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    int res = 0;
    dfs(g, dp, 0, -1, k, res);
    cout << res << '\n';
}

void solve2() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    int res = 0;
    auto ddfs = [&](auto&& self, int now, int par) -> void {
        dp[now][0] = 1;
        for (auto nxt : g[now]) {
            if (nxt == par) continue;
            self(self, nxt, now);
            for (int i = 0; i < k; i++) res += dp[now][i] * dp[nxt][k - i - 1];
            // for (int i = 0; i < k; i++) res += dp[now][k - i - 1] * dp[nxt][i];
            for (int i = 1; i <= k; i++) dp[now][i] += dp[nxt][i - 1];
        }
    };
    ddfs(ddfs, 0, -1);
    cout << res << '\n';
}

signed main() {
    int t = 1;
//    cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}
