// 609E 2100
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class UnionFind {
    int n;
    int link;
    vector<int> p;
public:
    UnionFind(int n) : n(n), p(n), link(0) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int find(int x) {
        return x == p[x] ? x : (p[x] = find(p[x]));
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            link++;
            return true;
        }
        return false;
    }
};

struct Edge {
    int w, u, v, idx;
    Edge() {}
    Edge(int w, int u, int v, int idx) : w(w), u(u), v(v), idx(idx) {}
};

int n, m;
vector<Edge> edges;
vector<vector<pair<int, int>>> tree;
const int LOG = 20;
vector<vector<int>> up;        // up[u][k] = 2^k-th ancestor of u
vector<vector<int>> maxEdge;   // maxEdge[u][k] = max edge on path from u to up[u][k]
vector<int> depth;

void dfs(int u, int p, int w) {
    depth[u] = p == -1 ? 0 : depth[p] + 1;
    up[u][0] = p;
    maxEdge[u][0] = w;
    for (int i = 1; i < LOG; i++) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
            maxEdge[u][i] = max(maxEdge[u][i - 1], 
                maxEdge[up[u][i - 1]][i - 1]);
        }
    }
    for (auto [v, w] : tree[u]) {
        if (v == p) continue;
        dfs(v, u, w);
    }
}

int getMaxEdge(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int res = 0;

    // 把u提升到和v一样高
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]) {
            res = max(res, maxEdge[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return res;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && up[u][i] != up[v][i]) {
            res = max(res, maxEdge[u][i]);
            res = max(res, maxEdge[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    res = max(res, maxEdge[u][0]);
    res = max(res, maxEdge[v][0]);
    return res;
}

void solve() {
    cin >> n >> m;
    edges.resize(m);
    tree.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = Edge(w, u, v, i);
    }
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.w < b.w;
    });
    long long mst = 0;
    UnionFind uf(n);
    vector<bool> isCul(m, false);
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w, idx = edges[i].idx;
        if (uf.merge(u, v)) {
            mst += w;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
            isCul[i] = true;
        }
    }

    // 树上倍增
    up.resize(n, vector<int>(LOG, -1));
    maxEdge.resize(n, vector<int>(LOG, 0));
    depth.resize(n, 0);
    dfs(0, -1, 0);
    vector<long long> res(m, 0);
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w, idx = edges[i].idx;
        if (!isCul[i]) {
            int maxEdgeOnPath = getMaxEdge(u, v);
            res[idx] = mst - maxEdgeOnPath + w;
        } else {
            res[idx] = mst;
        }
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
