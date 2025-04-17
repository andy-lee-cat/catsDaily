// 474F 2100
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <tuple>
using namespace std;

class SegmentTree {
    vector<int> s;
    vector<int> gcdt; // gcdTree
    vector<int> cntt; // cntTree
    int n;
public:
    SegmentTree(const vector<int> &s) : s(s) {
        n = s.size();
        gcdt.resize(4 * n + 5);
        cntt.resize(4 * n + 5);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            gcdt[node] = s[l];
            cntt[node] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        gcdt[node] = std::gcd(gcdt[node * 2], gcdt[node * 2 + 1]); 
        if (gcdt[node * 2] == gcdt[node * 2 + 1]) {
            cntt[node] = cntt[node * 2] + cntt[node * 2 + 1];
        } else {
            if (gcdt[node] == gcdt[node * 2]) {
                cntt[node] = cntt[node * 2];
            } else if (gcdt[node] == gcdt[node * 2 + 1]) {
                cntt[node] = cntt[node * 2 + 1];
            } else {
                cntt[node] = 0;
            }
        }
    };

    pair<int, int> query(int node, int l, int r, int x, int y) {
        if (l > y || r < x) return {0, 0};
        if (l >= x && r <= y) return {gcdt[node], cntt[node]};
        int mid = (l + r) / 2;
        auto [lgcd, lcnt] = query(node * 2, l, mid, x, y);
        auto [rgcd, rcnt] = query(node * 2 + 1, mid + 1, r, x, y);
        int gcd = std::gcd(lgcd, rgcd);
        if (lgcd == rgcd) {
            return {lgcd, lcnt + rcnt};
        } else {
            if (gcd == lgcd) {
                return {gcd, lcnt};
            } else if (gcd == rgcd) {
                return {gcd, rcnt};
            } else {
                return {gcd, 0};
            }
        }
    }
};

SegmentTree *st;

vector<int> s;

void solve() {
    int l, r;
    cin >> l >> r;
    l--, r--;
    auto [gcd, cnt] = st->query(1, 0, s.size() - 1, l, r);
    cout << r - l + 1 - cnt << '\n';
}

int main() {
    int n;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    st = new SegmentTree(s);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
