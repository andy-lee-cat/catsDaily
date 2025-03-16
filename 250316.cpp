// 1513C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define SIZE 200005
#define MOD 1000000007

long long add(long long a, long long b) {
    return (a + b) % MOD;
}

vector<vector<long long>> dp(10, vector<long long>(SIZE, 0));

void init() {
    // dp[i][j] = dp[i + 1][j - 1] when i < 9
    // dp[9][j] = dp[0][j - 1] + dp[1][j - 1]
    for (int j = 0; j < 10; j++)
        dp[j][0] = 1;
    for (int i = 1; i < SIZE; i++) {
        dp[9][i] = add(dp[0][i - 1], dp[1][i - 1]);
        for (int j = 8; j >= 0; j--)
            dp[j][i] = dp[j + 1][i - 1];
    }
}

void solve() {
    string n;
    int m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < n.length(); i++) {
        ans = add(ans, dp[n[i] - '0'][m]);
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
