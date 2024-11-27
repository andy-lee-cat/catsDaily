// 1336A 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;

void solve() {
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
    queue<int> q;
    vector<bool> vis(n);
    vector<int> p(n);
    vector<int> d(n);
    int depth = 0;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            int now = q.front(); q.pop();
            d[now] = depth;
            for (int nxt : g[now]) {
                if (!vis[nxt]) {
                    q.push(nxt);
                    vis[nxt] = true;
                    p[nxt] = now;
                }
            }
        }
        depth++;
    }
    vector<int> in(n);
    for (int i = 1; i < n; i++) 
        in[p[i]]++;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            pq.push({d[i], i});
        }
    }
    long long res = 0;
    vector<long long> dec(n);
    while (k--) {
        auto [val, now] = pq.top(); pq.pop();
        res += val;
        int par = p[now];
        in[par]--;
        dec[par] += dec[now] + 1;
        if (in[par] == 0) {
            pq.push({d[par] - dec[par], par});
        }
    }
    cout << res << '\n';
}

void solveOn() {
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
    vector<int> size(n);
    vector<int> depth(n);
    vector<int> val(n);
    auto dfs = [&](auto &&self, int now, int par) -> int {
        if (par != -1) depth[now] = depth[par] + 1;
        for (int nxt : g[now]) {
            if (nxt == par) continue;
            size[now] += self(self, nxt, now);
        }
        val[now] = depth[now] - size[now];
        return size[now] + 1;
    };
    dfs(dfs, 0, -1);
    nth_element(val.begin(), val.begin() + k, val.end(), greater<int>());
    long long res = accumulate(val.begin(), val.begin() + k, 0ll);
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solveOn();
    }
    return 0;
}
