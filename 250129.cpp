// 401C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m + 1) {
        cout << -1 << '\n';
        return;
    }
    if (m - 2 > 2 * n) {
        cout << -1 << '\n';
        return;
    }
    if (n == m) {
        for (int i = 0; i < n; i++) {
            cout << "01";
        }
        cout << '\n';
        return;
    }
    if (n == m + 1) {
        for (int i = 0; i < m; i++) {
            cout << "01";
        }
        cout << "0\n";
        return;
    }
    int d = m - n;
    for (int i = 0; i < n; i++) {
        if (d > 0) {
            cout << "1";
            d--;
        }
        cout << "10";
    }
    while (d--) cout << "1";
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
