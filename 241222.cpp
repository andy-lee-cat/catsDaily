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
    for (int i = 1; i < n; i++) 
        a[i] += a[i - 1];
    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        int res = lower_bound(a.begin(), a.end(), q) - a.begin();
        cout << res + 1 << '\n';
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
