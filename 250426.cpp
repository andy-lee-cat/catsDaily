// 1527C 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> dp(n);
    map<int, long long> sum;

    dp[0] = 0;
    sum[a[0]] = 1;
    // dp_i = dp_{i-1} + sum(j+1) for j < i and aj = ai
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + sum[a[i]];
        sum[a[i]] += i + 1;
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
