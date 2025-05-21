// 348A 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    int maxa = *max_element(a.begin(), a.end());
    int dev = sum / (n - 1);
    int mod = sum % (n - 1);
    dev += mod == 0 ? 0 : 1;
    cout << max(maxa, dev) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
