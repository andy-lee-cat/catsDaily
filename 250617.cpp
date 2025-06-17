// 1593E 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 1) 
            q.push(i);

    int res = 0;
    int left = n;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int now = q.front(); q.pop();
            left--;
            for (int u : g[now]) {
                deg[u]--;
                if (deg[u] == 1) {
                    q.push(u);
                }
            }
        }
        res++;
        if (res == k) {
            cout << left << '\n';
            return;
        }
    }
    cout << "0\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
