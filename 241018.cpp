// 455A 1500
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
    sort(a.begin(), a.end());
    vector<pair<int, int>> cnts;
    for (int v : a) {
        if (cnts.empty() || cnts.back().first != v) 
            cnts.push_back({v, 1});
        else
            cnts.back().second++;
    }
    int size = cnts.size();
    vector<long long> dp(size + 2);
    for (int i = 0; i < size; i++) {
        if (i == 0 || cnts[i].first != cnts[i - 1].first + 1)
            dp[i + 2] = dp[i + 1] + 1ll * cnts[i].first * cnts[i].second;
        else 
            dp[i + 2] = max(dp[i + 1], dp[i] + 1ll * cnts[i].first * cnts[i].second);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
