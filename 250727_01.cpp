// 1610C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int l = 0, r = n + 1;
    auto test = [&](int need) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] >= cnt && cnt + 1 + a[i] >= need) {
                cnt++;
            }
        } 
        return cnt >= need;
    };
    while (l < r) {
        int m = l + (r - l) / 2;
        if (test(m)) l = m + 1;
        else r = m;
    }
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
