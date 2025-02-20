// 977C 1200
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
    sort(a.begin(), a.end());
    if (k == 0) {
        if (a[0] == 1) {
            cout << -1 << '\n';
        } else {
            cout << 1 << '\n';
        }
        return;
    }

    if (k == n) {
        cout << a[n - 1] << '\n';
        return;
    }

    if (k > n) {
        cout << -1 << '\n';
        return;
    }

    if (a[k - 1] == a[k]) {
        cout << -1 << '\n';
    } else {
        cout << a[k - 1] << '\n';
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
