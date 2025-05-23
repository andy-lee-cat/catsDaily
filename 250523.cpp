// 1438C 2000
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (((i + j) % 2 == 0) ^ (a[i][j] % 2 == 0)) {
                a[i][j] += 1;
            }
            cout << a[i][j] << " \n"[j == m - 1];
        }
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
