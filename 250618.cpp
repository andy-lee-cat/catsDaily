// 1985F 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    long long l = 1, r = 1e13;
    while (l < r) {
        long long m = l + (r - l) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (1 + (m - 1) / c[i] >= h) {
                sum = h + 1;
                break;
            }
            sum += 1ll * (1 + ((m - 1) / c[i])) * a[i];
        }
        if (sum >= h) {
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
