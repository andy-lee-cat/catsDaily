// 1187E 2100
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


long long res = 0;
int n;
vector<vector<int>> g;
vector<long long> dp;
vector<int> s;

void dfs1(int v, int p) {
    s[v] = 1;
    dp[v] = 0;
    for (int u : g[v]) {
        if (u == p) continue;
        dfs1(u, v);
        s[v] += s[u];
        dp[v] += dp[u];
    }
    dp[v] += s[v];
};

void dfs2(int v, int p) {
    res = max(res, dp[v]);
    if (p != -1) {
        dp[v] = n - 2 * s[v] + dp[p];
        res = max(res, dp[v]);
    }
    for (int u : g[v]) {
        if (u == p) continue;
        dfs2(u, v);
    }
}

void solve() {
    cin >> n;
    res = 0;
    g.assign(n, vector<int>());
    dp.assign(n, 0);
    s.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1); 
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
