// 466c 1700
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % 3 != 0) {
        cout << "0\n";
        return;
    }
    long long need = sum / 3;
    int l = 0, r = n - 1;
    vector<int> possl, possr;
    long long lnow = a[0], rnow;
    while (l < n - 2) {
        while (l < n - 2 && lnow != need) {
            l++;
            lnow += a[l];
        }
        if (lnow == need) possl.push_back(l);
        lnow += a[l + 1];
        l++;
    }
    rnow = a[n - 1];
    while (r >= 2) {
        while (r >= 2 && rnow != need) {
            r--;
            rnow += a[r];
        }
        if (rnow == need) possr.push_back(r);
        rnow += a[r - 1];
        r--;
    }
    reverse(possr.begin(), possr.end());
    l = 0, r = 0;

    long long res = 0;
    while (l < possl.size() && r < possr.size()) {
        while (r < possr.size() && possr[r] <= possl[l] + 1) r++;
        res += possr.size() - r;
        l++;
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
