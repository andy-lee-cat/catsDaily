// 580c 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> leaf(n);
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            leaf[i] = true;
        }    
    }
    leaf[0] = false;

    int res = 0;
    auto dfs = [&](auto &&self, int v, int p, int c) -> void {
        if (a[v] == 0) c = m;
        else c--;
        if (c < 0) return;
        if (leaf[v]) {
            res++;
            return;
        } 
        for (auto u : g[v]) {
            if (u == p) continue;
            self(self, u, v, c);
        }
    };
    dfs(dfs, 0, -1, m);
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
