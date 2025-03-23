// 1418C 1500
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
    
    int MAX = 1e8;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = a[0];
    dp[0][1] = MAX;
    if (n < 2) {
        cout << a[0] << '\n';
        return;
    }
    dp[1][0] = a[0] + a[1];
    dp[1][1] = a[0];
    for (int i = 2; i < n; i++) {
        dp[i][0] = min({
            dp[i - 1][1] + a[i],
            dp[i - 2][1] + a[i] + a[i - 1]
        });
        dp[i][1] = min({
            dp[i - 1][0],
            dp[i - 2][0]
        });
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
