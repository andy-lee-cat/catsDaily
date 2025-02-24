// 1633D 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> dis;

void init() {
    int SIZE = 1e3;
    dis = vector<int>(SIZE + 1, 1e9);
    dis[1] = 0;
    for (int i = 1; i <= SIZE; i++) {
        for (int x = 1; x <= i; x++) {
            int nxt = i + i / x;
            if (nxt <= SIZE) {
                dis[nxt] = min(dis[nxt], dis[i] + 1);
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), v(n), cost(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    for (int i = 0; i < n; i++) 
        cost[i] = dis[b[i]];
    vector<int> dp(k + 1);
    // dp[n][k] = min(dp[n-1][k], dp[n-1][k-cost[n]] + v[n])
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + v[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
