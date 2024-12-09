// 20c 1900
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<unordered_map<int, int>> tmpg(n + 1);
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v) continue;
        if (u > v) swap(u, v);
        if (tmpg[u].find(v) == tmpg[u].end() || tmpg[u][v] > w) {
            tmpg[u][v] = w;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto [v, w] : tmpg[i]) {
            g[i].push_back({v, w});
            g[v].push_back({i, w});
        }
    }
    vector<int> pre(n + 1);
    vector<long long> dist(n + 1, 1e18);
    priority_queue<
        pair<long long, int>, 
        vector<pair<long long, int>>, 
        greater<pair<long long, int>>
    > pq;
    pq.push({0, 1});
    bool ok = false;
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        dist[u] = d;
        if (u == n) {
            ok = true;
            break;
        }
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }
    vector<int> path;
    for (int u = n; u != 1; u = pre[u]) {
        path.push_back(u);
    }
    cout << "1 ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " \n"[i == 0];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
