// 448D 1800
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    long long left = 0, right = 1ll * n * m + 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min((long long)m, (mid / i));
        }
        if (cnt < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
