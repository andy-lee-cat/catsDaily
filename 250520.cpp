// 1327C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        cin >> x >> y;
    }
    cout << n + m - 2 + n * m << '\n';
    for (int i = 0; i < n - 1; i++) cout << 'U';
    for (int j = 0; j < m - 1; j++) cout << 'L';
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) for (int j = 0; j < m - 1; j++) cout << 'R';
        else for (int j = 0; j < m - 1; j++) cout << 'L';
        cout << 'D';
    }
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
