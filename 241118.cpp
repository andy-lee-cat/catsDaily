#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        d[i] = a[i] - b[i];
    sort(d.begin(), d.end());
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int cnt = distance(d.begin(),
            upper_bound(d.begin(), d.end(), -d[i]));
        if (d[i] > 0) res--;
        res += n - cnt;
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
