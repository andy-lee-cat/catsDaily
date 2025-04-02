// 1702E 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class UnionFind {
public:
    vector<int> p, size;
    UnionFind(int n) : p(n), size(n, 1) {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        p[y] = x;
        size[x] += size[y];
    }
    int getSize(int x) {
        return size[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; i++) {
        if (a[i][0] == a[i][1]) {
            cout << "NO" << '\n';
            return;
        }
    }
    vector<vector<int>> link(n);
    for (int i = 0; i < n; i++) {
        link[a[i][0] - 1].push_back(i);
        link[a[i][1] - 1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (link[i].size() != 2) {
            cout << "NO" << '\n';
            return;
        }
    }
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        uf.merge(link[i][0], link[i][1]);
    }
    for (int i = 0; i < n; i++) {
        if (uf.getSize(i) % 2 != 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
