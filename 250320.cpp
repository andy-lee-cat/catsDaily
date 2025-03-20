// 1037D 1700
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void solve_2() {
    // 官方写法，排序
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> a(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        order[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), [&](int u, int j) {
            return order[u] < order[j];
        });
    }

    // bfs
    vector<bool> vis(n);
    vector<int> ans;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v]) 
                q.push(v);
    }

    if (equal(a.begin(), a.end(), ans.begin())) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n);
    vector<int> depth(n);
    // par[0] = 0;
    auto dfs = [&](auto&& self, int u, int p, int d) -> void {
        par[u] = p;
        depth[u] = d;
        for (int v : g[u]) {
            if (v == p) continue;
            self(self, v, u, d + 1);
        }
    };
    dfs(dfs, 0, -1, 0);
    vector<bool> vis(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    
    if (a[0] != 0) {
        cout << "No\n";
        return;
    }
    
    vis[0] = true;
    int nowdepth = 0;
    for (int i = 1; i < n; i++) {
        if (!vis[par[a[i]]] || depth[a[i]] < nowdepth) {
            cout << "No\n";
            return;
        }
        nowdepth = depth[a[i]];
        vis[a[i]] = true;
    }

    vector<vector<int>> nodes(nowdepth + 1);
    for (int i = 0; i < n; i++)
        nodes[depth[a[i]]].push_back(a[i]);
    for (int i = 1; i <= nowdepth; i++) {
        int pidx = 0;
        for (int v : nodes[i]) {
            // 这里if改成while了
            while (nodes[i - 1][pidx] != par[v]) {
                pidx++;
                if (pidx >= nodes[i - 1].size()) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve_2();
    }
    return 0;
}
