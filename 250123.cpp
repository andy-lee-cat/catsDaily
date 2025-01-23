// 1338A 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            res = max(res, a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }
    int ans = 0;
    while (res) {
        res >>= 1;
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
