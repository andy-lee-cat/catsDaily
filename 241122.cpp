// 1353D 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<tuple<int, int, int>> q;
    q.push({n, 0, n - 1}); 
    int now = 1;
    while (!q.empty()) {
        auto [len, l, r] = q.top(); q.pop();
        l = -l;
        int m = (l + r) / 2;
        a[m] = now++;
        if (l < m) q.push({m - l, -l, m - 1});
        if (m < r) q.push({r - m, -(m + 1), r});
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
