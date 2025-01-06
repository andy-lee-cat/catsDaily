// 550B 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i < (1 << n); i++) {
        int tot = 0;
        int mina = 1e9, maxa = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                tot += a[j];
                mina = min(mina, a[j]);
                maxa = max(maxa, a[j]);
            }
        }
        if (tot >= l && tot <= r && maxa - mina >= x)
            cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
