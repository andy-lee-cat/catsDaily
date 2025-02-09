// 1167c 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class UnionFind {
    int n;
    vector<int> p;
    vector<int> size;
public:
    UnionFind(int n) : n(n) {
        p.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    while (m--) {
        int size;
        cin >> size;
        vector<int> v(size);
        for (int i = 0; i < size; i++) {
            cin >> v[i];
            v[i]--;
        }
        for (int i = 1; i < size; i++) {
            uf.merge(v[0], v[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << uf.getSize(i) << " \n"[i == n - 1]; 
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
