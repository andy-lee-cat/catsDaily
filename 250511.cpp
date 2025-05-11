// 372A 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 1, r = n + 1; // gai
    while (l < r) {
        int m = l + (r - l) / 2;
        // a[0]-a[m-1] ___ a[n-m]-a[n-1]
        if (m - 1 >= n - m) {
            r = m;
            continue;
        }

        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (a[i] * 2 > a[i + n - m]) {
                flag = false;
                break;
            }
        }
        if (flag) l = m + 1;
        else r = m;
    }
    cout << n - (l - 1) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
