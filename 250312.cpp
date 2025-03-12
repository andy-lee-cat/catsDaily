// 1221D 1800
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<vector<long long>> dp(n, vector<long long>(3, LLONG_MAX));
    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = 2 * b[0];
    for (int i = 1; i < n; i++) {
        for (int add = 0; add <= 2; add++) {
            for (int last_add = 0; last_add <= 2; last_add++) {
                if (a[i - 1] + last_add != a[i] + add) {
                    dp[i][add] = min(dp[i][add], dp[i - 1][last_add] + add * b[i]);
                }
            }
        }
    }
    cout << min({
        dp[n - 1][0],
        dp[n - 1][1],
        dp[n - 1][2]
    }) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
