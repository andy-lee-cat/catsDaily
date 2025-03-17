// 977E 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 

    vector<bool> vis(n);
    auto dfs = [&](auto &&f, int u, int v) -> void {
        vis[u] = true;
        for (int x : g[u]) {
            if (x == v || vis[x]) continue;
            f(f, x, u);
        }
    };

    int res = 0;
    for (int start = 0; start < n; start++) {
        if (vis[start]) continue;
        int now = start;
        bool loop = false;
        int len = 1;
        int last = -1;
        while (g[now].size() == 2) {
            int temp_now = now;
            now = g[now][0] == last ? g[now][1] : g[now][0];
            last = temp_now;
            vis[now] = true;
            len++;
            if (now == start) {
                if (len > 2) res++;
                loop = true;
                break;
            }
        } 
        if (!loop) {
            dfs(dfs, now, -1);
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
