// 327A 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] == 1) ^ (l <= i && i <= r)) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
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
