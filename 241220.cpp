// 1374D 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
        a[i] = (k - a[i]) % k;
    }
    sort(a.begin(), a.end());
    int now = 0;
    int cnt = 0;
    int mxnum = 0, mxcnt = 0;
    for (int v : a) {
        if (v == 0) continue;
        if (v == now) cnt++;
        else {
            if (cnt >= mxcnt) {
                mxcnt = cnt;
                mxnum = now;
            }
            now = v;
            cnt = 1;
        }
    }
    if (cnt >= mxcnt) {
        mxcnt = cnt;
        mxnum = now;
    }
    long long res = 1ll * (mxcnt - 1) * k + mxnum + 1;
    if (mxnum == 0) {
        // only 0 in a
        res = 0;
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
