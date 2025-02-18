// 1285B 1300
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long res = accumulate(a.begin(), a.end(), 0LL);
    long long sum = 0;
    long long mmin = a[0];
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
        ans = max(ans, sum);
    }
    sum = a[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, sum + a[i] - mmin);
        sum += a[i];
        mmin = min(mmin, sum);
    }
    if (ans >= res) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
