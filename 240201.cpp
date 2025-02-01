// 1369C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> w(k);
    for (int i = 0; i < k; i++)
        cin >> w[i];
    sort(w.begin(), w.end());
    sort(a.begin(), a.end(), greater<long long>());
    long long res = 0;
    int idx = 0;
    for (idx = 0; idx < k; idx++) {
        res += a[idx];
        if (w[idx] == 1)
            res += a[idx];
        w[idx]--;
    }
    for (int i = 0; i < k; i++) {
        if (w[i] == 0) continue;
        res += a[idx + w[i] - 1];
        idx += w[i];
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
