// 1843E 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>  segs(m);
    for (int i = 0; i < m; i++)
        cin >> segs[i].first >> segs[i].second;
    int q;
    cin >> q;
    vector<int> xs(q);
    for (int i = 0; i < q; i++)
        cin >> xs[i];
    
    vector<int> xset(n + 1, 0);
    auto check = [&](int idx) -> bool {
        xset.assign(n + 1, 0);
        for (int i = 0; i <= idx; i++)
            xset[xs[i]] = 1;
        for (int i = 1; i <= n; i++) 
            xset[i] += xset[i - 1];
        for (auto [segl, segr] : segs) 
            if ((xset[segr] - xset[segl - 1]) * 2 > segr - segl + 1)
                return true;
        return false;
    };

    int l = 0, r = q;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == q) {
        cout << -1 << '\n';
    } else {
        cout << l + 1 << '\n';
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
