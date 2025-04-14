// 380C 2000
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<tuple>
using namespace std;


struct Node {
    int match = 0;
    int open = 0;
    int close = 0;
};

string s;
vector<Node> seg;
int n;

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') {
            seg[id].open = 1;
        } else {
            seg[id].close = 1;
        }
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);

    int t = min(seg[id * 2].open, seg[id * 2 + 1].close);
    seg[id].match = seg[id * 2].match + seg[id * 2 + 1].match + t;
    seg[id].open = seg[id * 2].open + seg[id * 2 + 1].open - t;
    seg[id].close = seg[id * 2].close + seg[id * 2 + 1].close - t;
}

Node query(int id, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return {0, 0, 0};
    if (ql <= l && qr >= r) return seg[id];
    int m = (l + r) / 2;
    Node left = query(id * 2, l, m, ql, qr);
    Node right = query(id * 2 + 1, m + 1, r, ql, qr);

    Node res;
    int t = min(left.open, right.close);
    res.match = left.match + right.match + t;
    res.open = left.open + right.open - t;
    res.close = left.close + right.close - t;
    return res;
}


int main() {
    cin >> s;
    n = s.length();
    seg.resize(n * 4 + 5);
    build(1, 0, n - 1);
    int t = 1;
    cin >> t;
    while (t--) {
        int ql, qr;
        cin >> ql >> qr;
        ql--, qr--;
        Node res = query(1, 0, n - 1, ql, qr);
        cout << res.match * 2 << '\n';
    }
}


/*
string s;
// l_idx, r_idx
vector<pair<int, int>> ps;
vector<pair<int, int>> psl;
vector<pair<int, int>> psr;

void init() {
    stack<int> stk;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            if (!stk.empty()) {
                int j = stk.top(); stk.pop(); 
                ps.push_back({j, i});
            }
        }
    }
    psl.assign(ps.begin(), ps.end());
    psr.assign(ps.begin(), ps.end());
    sort(psl.begin(), psl.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    sort(psr.begin(), psr.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
}

void solve() {
    int ql, qr;
    cin >> ql >> qr;
    ql--, qr--;
    int l, r;
    l = 0, r = ps.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (psl[m].first < ql) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    int l_idx = l;
    if (l_idx >= psl.size() || psl[l_idx].first > qr) {
        cout << 0 << '\n';
        return;
    }
    l = 0, r = ps.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (psr[m].second <= qr) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    int r_idx = l - 1;
    if (r_idx < 0 || psr[r_idx].second < ql) {
        cout << 0 << '\n';
        return;
    }
    // 右区间限制
    auto [rl, rr] = psr[r_idx];
    // 左区间限制
    auto [ll, lr] = psl[l_idx];

    // case1: 左包右，说明左区间的r不符合条件
    if (ll <= rl && lr >= rr) {
        cout << rr - rl + 1 << '\n';
        return;
    }

    // case2: 右包左
    if (rl <= ll && rr >= lr) {
        cout << lr - ll + 1 << '\n';
        return;
    }

    // case3: 左右交叉
    // 找右r对应的[rl, rr]在左的idx
    l = 0, r = ps.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (psl[m].first < rl) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << (l - l_idx) * 2 + psl[l].second - psl[l].first + 1 << '\n';
}

int main() {
    cin >> s;
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
*/