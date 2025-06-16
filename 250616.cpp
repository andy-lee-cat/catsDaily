// 1272D 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<pair<int, int>> incs;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] <= a[incs.back().second]) {
            incs.push_back({i, i});
        } else {
            incs.back().second = i;
        }
    }
    int res = 0;
    for (auto [l, r] : incs) {
        res = max(res, r - l + 1);
    }
    for (int i = 0; i < incs.size() - 1; i++) {
        auto [ll, lr] = incs[i];
        auto [rl, rr] = incs[i + 1];
        // 长度小于等于1，加了也没用
        if (lr - ll + 1 <= 1 || rr - rl + 1 <= 1) 
            continue;
        // 加起来也不够大，加了也没用
        if (lr - ll + 1 + rr - rl + 1 - 1 <= res) 
            continue;

        if (a[lr - 1] < a[rl] || a[lr] < a[rl + 1]) 
            res = max(res, rr - ll + 1 - 1);
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
