// 1474C 1700
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = false;
    vector<pair<int, int>> res;
    for (int i = 0; i < 2 * n - 1; i++) {
        int sum = a[2 * n - 1] + a[i];
        res.clear();
        multiset<int> s;
        for (int v : a)
            s.insert(v);
        
        while (!s.empty()) {
            int r = *s.rbegin();
            int l = sum - r;
            s.erase(s.find(r));
            if (s.find(l) == s.end()) 
                break;
            s.erase(s.find(l));
            res.push_back({l, r});
            sum = r;
        }
        if (s.empty()) {
            ok = true;
            break;
        }
    } 
    if (ok) {
        cout << "Yes\n";
        cout << res[0].first + res[0].second << '\n';
        for (auto [l, r] : res) {
            cout << l << ' ' << r << '\n';
        }
    } else {
        cout << "No\n";
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
