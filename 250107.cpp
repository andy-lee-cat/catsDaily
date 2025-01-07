// 1165D 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 1ll * a[0] * a[n - 1];
    set<int> divs;
    for (auto v : a) {
        if (ans % v != 0) {
            cout << -1 << endl;
            return;
        }
        divs.insert(v);
    }
    for (int i = 2; 1ll * i * i <= ans; i++) {
        if (ans % i == 0) {
            if (!divs.count(i) || !divs.count(ans / i)) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
