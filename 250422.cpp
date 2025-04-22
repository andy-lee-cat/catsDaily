// 2B 2000
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define PII pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    bool have_zero = false;
    int zero_x, zero_y;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (a[i][j] == 0) 
                have_zero = true, zero_x = i, zero_y = j;

    auto cul = [&](int x) -> PII {
        if (x == 0) return {1, 1};
        int cnt2 = 0, cnt5 = 0;
        while (x && x % 2 == 0) {
            cnt2++;
            x /= 2;
        }
        while (x && x % 5 == 0) {
            cnt5++;
            x /= 5;
        }
        return {cnt2, cnt5};
    };
    vector<vector<PII>> b(n, vector<PII>(n, {0, 0}));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            b[i][j] = cul(a[i][j]);
    
    vector<vector<PII>> dp(n, vector<PII>(n, {0, 0}));
    vector<vector<PII>> from(n, vector<PII>(n, {0, 0}));
    dp[0][0] = b[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0].first = dp[i - 1][0].first + b[i][0].first;
        dp[i][0].second = dp[i - 1][0].second + b[i][0].second;
        from[i][0] = {0, 0};
    }
    for (int j = 1; j < n; j++) {
        dp[0][j].first = dp[0][j - 1].first + b[0][j].first;
        dp[0][j].second = dp[0][j - 1].second + b[0][j].second;
        from[0][j] = {1, 1};
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            // first
            if (dp[i - 1][j].first < dp[i][j - 1].first) {
                from[i][j].first = 0;
                dp[i][j].first = dp[i - 1][j].first + b[i][j].first;
            } else {
                from[i][j].first = 1;
                dp[i][j].first = dp[i][j - 1].first + b[i][j].first;
            }
            // second
            if (dp[i - 1][j].second < dp[i][j - 1].second) {
                from[i][j].second = 0;
                dp[i][j].second = dp[i - 1][j].second + b[i][j].second;
            } else {
                from[i][j].second = 1;
                dp[i][j].second = dp[i][j - 1].second + b[i][j].second;
            }
        }
    }
    int res = min(dp[n - 1][n - 1].first, dp[n - 1][n - 1].second);
    if (have_zero && res > 0) {
        cout << 1 << '\n';
        int x = 0, y = 0;
        while (x < zero_x) {
            cout << 'D';
            x++;
        }
        while (y < zero_y) {
            cout << 'R';
            y++;
        }
        while (x < n - 1) {
            cout << 'D';
            x++;
        }
        while (y < n - 1) {
            cout << 'R';
            y++;
        }
        cout << '\n';
        return;
    }
    string ans(2 * n - 2, 'R'); 
    int x = n - 1, y = n - 1;
    int pos = 2 * n - 3;
    if (dp[n - 1][n - 1].first < dp[n - 1][n - 1].second) {
        while (x > 0 || y > 0) {
            if (from[x][y].first == 0) {
                ans[pos--] = 'D';
                x--;
            } else {
                ans[pos--] = 'R';
                y--;
            }
        }
    } else {
        while (x > 0 || y > 0) {
            if (from[x][y].second == 0) {
                ans[pos--] = 'D';
                x--;
            } else {
                ans[pos--] = 'R';
                y--;
            }
        }
    }
    cout << res << '\n';
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
