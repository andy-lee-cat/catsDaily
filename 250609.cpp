// 1907D 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> segs(n);
    for (int i = 0; i < n; i++)
        cin >> segs[i].first >> segs[i].second;
    int l = 0, r = 1e9 + 1;
    auto check = [&](int d) -> bool {
        int vl = 0, vr = 0; // valid range
        for (int i = 0; i < n; i++) {
            vl = vl - d;
            vr = vr + d;
            int left = segs[i].first, right = segs[i].second;
            vl = max(vl, left);
            vr = min(vr, right);
            if (vl > vr) return false;
        }
        return true;
    };
    while (l < r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
