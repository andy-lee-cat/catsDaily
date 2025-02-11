// 893C 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class UnionFind {
    int n;
    vector<int> p, v;
    long long res;
public:
    UnionFind(int n, vector<int>& values) : n(n), v(values) {
        p.resize(n);
        res = 0;
        for (int i = 0; i < n; i++) {
            p[i] = i;
            res += v[i];
        }
    }

    int Find(int x) {
        return p[x] == x ? x : p[x] = Find(p[x]);
    }

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            p[x] = y;
            res -= max(v[x], v[y]);
            v[y] = min(v[x], v[y]);
        }
    }

    int getValue(int x) {
        return v[Find(x)];
    }

    long long getRes() {
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    UnionFind uf(n, a);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        uf.Union(x - 1, y - 1);
    }
    cout << uf.getRes() << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
