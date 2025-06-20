// 1904C 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, kk;
    cin >> n >> kk;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (kk >= 3) {
        cout << 0 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    long long res = *min_element(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) 
        res = min(res, a[i + 1] - a[i]);
    if (kk == 1) {
        cout << res << '\n';
        return;
    }

    // kk == 2
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < n; j++) {
            while (k < n && a[i] + a[j] > a[k]) {
                k++;
            }
            if (k < n) res = min(res, abs(a[k] - a[i] - a[j]));
            res = min(res, abs(a[i] + a[j] - a[k - 1]));
        }
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
