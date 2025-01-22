// 2A 1500
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, int>> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i].first >> vs[i].second;
    }
    map<string, int> mp;
    int max_res = INT_MIN;
    for (int i = 0; i < n; i++) {
        mp[vs[i].first] += vs[i].second;
    }
    for (int i = 0; i < n; i++) {
        max_res = max(max_res, mp[vs[i].first]);
    }
    set<string> res;
    for (int i = 0; i < n; i++) {
        if (mp[vs[i].first] == max_res) {
            res.insert(vs[i].first);
        }
    }
    int m = res.size();
    mp.clear();
    for (int i = 0; i < n; i++) {
        mp[vs[i].first] += vs[i].second;
        if (mp[vs[i].first] >= max_res && res.count(vs[i].first)) {
            cout << vs[i].first << '\n';
            return;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
