// 580B 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i].first >> f[i].second;
    }
    sort(f.begin(), f.end());
    long long res = 0;
    int l = 0;
    long long now = 0;
    for (int r = 0; r < n; r++) {
        now += f[r].second;
        while (f[r].first - f[l].first >= d) {
            now -= f[l].second;
            l++;
        }
        res = max(res, now);
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
