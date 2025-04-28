// 1741E 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    vector<bool> dp(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int v = i - a[i] - 1;
        if (v >= 0) g[v].push_back(i);
    }
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        if (!dp[i - 1]) continue;
        int nxt = i + a[i];
        if (nxt <= n) dp[nxt] = true;
        for (int j : g[i - 1]) dp[j] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
