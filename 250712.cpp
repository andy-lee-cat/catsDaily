// 1554B 1700
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    long long res = 1 * 2 - k * (a[1] | a[2]);
    if (n < 1000) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                res = max(res, 1ll * i * j - k * (a[i] | a[j]));
            }
        }
    } else {
        for (int i = n - 1; i >= n - 1000; i--) {
            for (int j = i + 1; j <= n; j++) {
                res = max(res, 1ll * i * j - k * (a[i] | a[j]));
            }
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
