// 478B 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    long long minans = 0, maxans = 0;
    maxans = 1ll * (n - m + 1) * (n - m) / 2;
    int k = n / m, left = n % m;;
    int more = n / m + 1, more_cnt = left;
    int less = n / m, less_cnt = m - left;
    minans = 1ll * more * (more - 1) / 2 * more_cnt +
        1ll * less * (less - 1) / 2 * less_cnt;
    cout << minans << ' ' << maxans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
