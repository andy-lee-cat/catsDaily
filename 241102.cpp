#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, a[i] - a[i - 1]);
    ans = max(a[0] * 2, ans);
    ans = max((l - a[n - 1]) * 2, ans);
    // cout << fixed << setprecision(10) << ans / 2.0 << '\n';
    cout << ans / 2.0 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
