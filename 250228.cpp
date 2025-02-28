// 277A 1400
// 建图用二分图更好
#include<iostream>
#include<algorithm>
#include<vector>
#include <stack>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<vector<int>> g(m);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    // build graph
    int res = 0;
    vector<bool> need(m);
    for (int i = 0; i < n; i++) {
        if (a[i].size() == 0) {
            res++; 
            continue;
        }
        if (a[i].size() > 0) need[a[i][0]] = true;
        for (int j = 1; j < a[i].size(); j++) {
            int u = a[i][j - 1], v = a[i][j];
            g[u].push_back(v);
            g[v].push_back(u); 
            need[u] = need[v] = true;
        }
    }

    if (res == n) {
        cout << n << '\n';
        return;
    }

    // dfs
    vector<bool> vis(n);
    for (int i = 0; i < m; i++) {
        if (!need[i] || vis[i]) continue;
        vis[i] = true;
        res++;
        // dfs(i)
        stack<int> s;
        s.push(i);
        while (!s.empty()) {
            int u = s.top(); s.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    s.push(v);
                }
            }
        }
    }
    cout << res - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
