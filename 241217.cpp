// 1201c 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int l = 0, r = 2e9 + 2;
    int tempk = k;
    while (l < r) {
        int m = l + (r - l) / 2;
        int cnt = 0;
        k = tempk;
        bool possible = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > m) cnt++;
            else if (m - a[i] <= k) {
                k -= m - a[i];
                cnt++;
            } else {
                break;
            }
            if (cnt >= (n + 1) / 2) {
                possible = true;
                break;
            }
        }
        if (possible)
            l = m + 1;
        else 
            r = m;
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
