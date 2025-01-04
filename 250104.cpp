// 706C 1600
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
    vector<string> ws(n);
    vector<string> rws(n);
    for (int i = 0; i < n; i++) {
        cin >> ws[i];
        string temp = ws[i];
        reverse(temp.begin(), temp.end());
        rws[i] = temp;
    }
    long long MAX = 1e18;
    vector<vector<long long>> dp(n, vector<long long>(2, MAX));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
        // dp[i][0]
        if (ws[i] >= ws[i - 1]) 
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (ws[i] >= rws[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        
        // dp[i][1]
        if (rws[i] >= ws[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        if (rws[i] >= rws[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
    }
    long long ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (ans == MAX)
        cout << -1 << endl;
    else
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
