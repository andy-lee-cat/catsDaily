// 1304C 1500
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> vistors(n);
    for (int i = 0; i < n; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        vistors[i] = {t, l, r};
    }

    int lastt = 0;
    int ll = m, rr = m;
    for (auto [t, l, r] : vistors) {
        int dt = t - lastt;
        ll -= dt;
        rr += dt;
        if (rr < l || ll > r) {
            cout << "NO\n";
            return;
        }
        ll = max(ll, l);
        rr = min(rr, r);
        lastt = t;
    }
    cout << "YES\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
