// 1538c 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int left = l - a[i];
        int right = r - a[i];
        res += upper_bound(a.begin(), a.end(), right) -
                lower_bound(a.begin(), a.end(), left);
        if (l <= 2 * a[i] && 2 * a[i] <= r)
            res--;
    }
    cout << res / 2 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
