// 1915F 1500
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int n) : n(n) {
        tree.resize(4 * n + 5, 0);
    }
    int query(int l, int r, int node, int s, int e) {
        if (l > e || r < s) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        int lres = query(l, r, 2 * node, s, m);
        int rres = query(l, r, 2 * node + 1, m + 1, e);
        return lres + rres;
    }
    void update(int idx, int addval, int node, int s, int e) {
        if (s == e) {
            tree[node] += addval;
            return;
        }
        int m = (s + e) / 2;
        if (idx <= m) {
            update(idx, addval, 2 * node, s, m);
        } else {
            update(idx, addval, 2 * node + 1, m + 1, e);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());

    // 离散化
    map<int, int> idxs;
    for (auto [a, b] : ab) 
        idxs[b] = 0;
    int idx = 0;
    for (auto [b, v] : idxs)
        idxs[b] = idx++;
    
    vector<int> bs(n);
    for (int i = 0; i < n; i++)
        bs[i] = idxs[ab[i].second];

    // b ∈ [0, n-1]
    // 现在只需要按顺序遍历bs，对每个b，查找已有多少b大于当前b
    SegmentTree st(n);
    long long res = 0;
    for (int b : bs) {
        int cnt = st.query(b + 1, INT_MAX, 1, 0, n - 1);
        res += cnt;
        st.update(b, 1, 1, 0, n - 1);
    }
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
