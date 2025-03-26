// 670D 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    long long l = 0, r = 2e9 + 1;
    while (l < r) {
        long long m = l + (r - l) / 2;
        long long cnt = k;
        for (int i = 0; i < n; i++) {
            long long need = m * a[i] - b[i];
            if (need > 0) cnt -= need;
            if (cnt < 0) break;
        }
        if (cnt < 0) r = m;
        else l = m + 1;
    }
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
