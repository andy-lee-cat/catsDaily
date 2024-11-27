// 279b 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    int l = 0, r = 0;
    int sum = 0;
    if (accumulate(a.begin(), a.end(), 0) <= t) {
        cout << n << '\n';
        return;
    }
    int res = 0;
    for (r = 0; r < n; r++) {
        sum += a[r];
        if (sum > t) {
            res = r - l;
            break;
        }
    }
    for (l = 1; l < n; l++) {
        sum -= a[l - 1];
        while (r < n && sum <= t) {
            r++;
            sum += a[r];
        }
        res = max(res, (r - l + n) % n);
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
