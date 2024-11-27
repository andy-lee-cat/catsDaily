// 241116
// 698A 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool ch = true;
    int now = -1;
    int res = 0;
    for (auto x : a) {
        int c0 = x & 1, c1 = x >> 1;
        if (now == -1) {
            if (c0 && c1) 
                ch = true;
            else
                ch = false;
            if (c0) 
                now = 0, res++;
            else if (c1) 
                now = 1, res++;
        } else if (now == 1) {
            if (c0) {
                now = 0;
                res++;
            } else if (c1 && ch) {
                ch = false;
                now = 1;
                res++;
            } else {
                now = -1;
                ch = true;
            }
            if (!(c0 && c1)) ch = false;
        } else {
            if (c1) {
                now = 1;
                res++;
            } else if (c0 && ch) {
                ch = false;
                now = 0;
                res++;
            } else {
                now = -1;
                ch = true;
            }
            if (!(c0 && c1)) ch = false;
        }
    }
    cout << n - res << '\n';
}


void solvedp() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<array<int, 3>> dp(n + 1);
    dp[0] = {0, 0, 0};
    for (int i = 1; i <= n; i++) {
        int x0 = a[i - 1] & 1, x1 = a[i - 1] >> 1;
        dp[i][0] = max(
            dp[i - 1][1] + x0,
            dp[i - 1][2] + x0
        );
        dp[i][1] = max(
            dp[i - 1][0] + x1,
            dp[i - 1][2] + x1
        );
        dp[i][2] = max({
            dp[i - 1][0],
            dp[i - 1][1],
            dp[i - 1][2]
        });           
        if (!x0) dp[i][0] = -1;
        if (!x1) dp[i][1] = -1;
    }
    cout << n - max({
        dp[n][0],
        dp[n][1],
        dp[n][2]
    }) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        // solve();
        solvedp();
    }
    return 0;
}
