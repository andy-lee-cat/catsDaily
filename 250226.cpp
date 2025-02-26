// 1097B 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & 1 << i) sum += a[i];
            else sum -= a[i];
        }
        if (sum % 360 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
