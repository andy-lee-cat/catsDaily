// 1833E 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class UnionFind {
    vector<int> p;
    int cnt;
public:
    UnionFind(int n) {
        p.resize(n);
        cnt = n;
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int x) {
        if (p[x] == x) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    bool merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return true;
        p[px] = p[y];
        cnt--;
        return false;
    }

    int getSize() {
        return cnt;
    }
};  

void solve() {
    int n;
    cin >> n;
    vector<set<int>> g(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u; u--;
        g[u].insert(i);
        g[i].insert(u);
    }

    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            if (v > u) continue;
            edges.push_back({v, u});
        }
    }

    UnionFind uf(n);
    int loop = 0;
    int cnt = 0;
    for (auto [u, v] : edges) {
        bool flag = uf.merge(u, v);
        if (flag) loop++;
    }
    cnt = uf.getSize();
    int min_res, max_res;
    if (loop == 0) {
        min_res = 1;
        max_res = cnt;
    } else {
        if (cnt == loop) {
            min_res = loop;
            max_res = loop;
        } else {
            min_res = loop + 1;
            max_res = cnt;
        }
    }
    cout << min_res << ' ' << max_res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
