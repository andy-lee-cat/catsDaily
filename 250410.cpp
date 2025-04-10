// 427C 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    int m;
    cin >> m;
    vector<vector<int>> g(n + 1), rg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    vector<bool> vis(n + 1);
    vector<int> s;
    auto dfs1 = [&](auto&& self, int u) -> void {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v])
                self(self, v);
        s.push_back(u);
    };
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(dfs1, i);
    vector<int> color(n + 1);
    int sccCnt = 0;
    auto dfs2 = [&](auto&& self, int u) -> void {
        color[u] = sccCnt;
        for (int v : rg[u])
            if (color[v] == 0)
                self(self, v);
    };
    for (int i = n - 1; i >= 0; i--) {
        int u = s[i];
        if (!color[u]) {
            sccCnt++;
            dfs2(dfs2, u);
        }
    }
    vector<int> sccCost(sccCnt + 1, INT_MAX);
    vector<int> sccCnts(sccCnt + 1);
    for (int i = 1; i <= n; i++) {
        int c = color[i];
        if (cost[i] < sccCost[c]) {
            sccCost[c] = cost[i];
            sccCnts[c] = 1;
        } else if (cost[i] == sccCost[c]) {
            sccCnts[c]++;
        }
    }
    long long resCost = 0, resCnt = 1;
    for (int i = 1; i <= sccCnt; i++) {
        resCost += sccCost[i];
        resCnt = (resCnt * sccCnts[i]) % 1000000007;
    }
    cout << resCost << ' ' << resCnt << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
