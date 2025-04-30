// 1730B 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] *= 2;
    }   
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int l = 0, r = 1e9;
    int resl = 0, resr = 0;

    // (x[i] - pos) / 2 + t[i] <= dtime / 2
    auto check = [&](int dtime) -> bool {
        int left = 0, right = 1e9;
        for (int i = 0; i < n; i++) {
            left = max(left,  x[i] - (dtime - 2 * t[i]));
            right = min(right, (dtime - 2 * t[i]) + x[i]);
            if (left > right) return false;
        }
        resl = left, resr = right;
        return true;
    };

    l = 0, r = 1e9;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (resl % 2 == 0) {
        cout << resl / 2 << '\n';
    } else {
        cout << resl / 2;
        cout << ".5\n";
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
