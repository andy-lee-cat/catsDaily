// 189a 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    vector<int> a(3);
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int res = 0;
    int max0 = n / a[0];
    for (int i = max0; i >= 0; i--) {
        int left0 = n - i * a[0];
        if (left0 == 0) {
            res = max(res, i);
            continue;
        }
        int max1 = left0 / a[1];
        for (int j = max1; j >= 0; j--) {
            int left1 = n - i * a[0] - j * a[1];
            if (left1 == 0) {
                res = max(res, i + j);
                continue;
            }
            if (left1 % a[2] == 0) {
                res = max(res, i + j + left1 / a[2]);
            }
        }
    }
    cout << res << '\n';
}

void solve2() {
    int n;
    vector<int> a(3);
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    int dp[4001] = {0};
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > a[j] && dp[i - a[j]] != 0 || i == a[j]) {
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}
