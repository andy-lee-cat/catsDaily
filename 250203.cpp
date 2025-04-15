// 545D 1300
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
    sort(a.begin(), a.end());
    int res = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t <= a[i]) {
            res++;
            t += a[i];
        }
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
