// 1373D 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long max_subarray(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    vector<long long> dp(n);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max((long long)a[i], dp[i - 1] + a[i]);
    }
    long long max_dp = *max_element(dp.begin(), dp.end());
    return max(0ll, max_dp);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> d1, d2;
    for (int i = 0; i + 1 < n; i += 2) {
        d1.push_back(a[i + 1] - a[i]);
    }
    for (int i = 1; i + 1 < n; i += 2) {
        d2.push_back(a[i] - a[i + 1]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i+= 2)
        ans += a[i];
    long long add = 0;
    long long add1 = max_subarray(d1);
    long long add2 = max_subarray(d2);
    add = max(add1, add2);
    cout << ans + add << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
