// 1520D 1200
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) 
        cnt[a[i]]++;
    long long res = 0;
    for (auto [k, v] : cnt) {
        res += 1ll * v * (v - 1) / 2;
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
