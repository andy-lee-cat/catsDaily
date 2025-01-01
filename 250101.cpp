// 545C 1500
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> h[i];
    vector<pair<int, int>> xhs(n);
    for (int i = 0; i < n; i++)
        xhs[i] = {x[i], h[i]};
    sort(xhs.begin(), xhs.end());
    vector<pair<bool, bool>> can(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) can[i].first = true;
        else if (xhs[i].first - xhs[i].second > xhs[i - 1].first) can[i].first = true;
        if (i == n - 1) can[i].second = true;
        else if (xhs[i].first + xhs[i].second < xhs[i + 1].first) can[i].second = true;
    }
    vector<pair<int, int>> seg;
    for (int i = 0; i < n; i++) {
        if (can[i].first) seg.push_back({x[i] - h[i], x[i]});
        if (can[i].second) seg.push_back({x[i], x[i] + h[i]});
    }
    sort(seg.begin(), seg.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }); 

    map<int, int> dp;
    int res = 0;
    for (auto [l, r] : seg) {
        auto it = dp.lower_bound(l);
        if (it == dp.begin()) {
            res = max(res, 1);
        } else {
            it--;
            res = max(res, it->second + 1);
        }
        dp[r] = res;
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
