// 1334c 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[(i + 1) % n];
    long long ans = LLONG_MAX;
    vector<long long> add(n);
    for (int i = 0; i < n; i++) {
        add[i] = max(0ll, a[i] - b[i]);
    }
    ans = accumulate(add.begin(), add.end(), 0ll) 
        + min(
            *min_element(a.begin(), a.end()), 
            *min_element(b.begin(), b.end())
        );
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
