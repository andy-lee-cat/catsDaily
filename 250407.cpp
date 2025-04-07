// 1374E1 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include <tuple>
using namespace std;

void partSum(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a, b, both;
    for (int i = 0; i < n; i++) {
        int t, ai, bi;
        cin >> t >> ai >> bi;
        if (ai == 1 && bi == 1) {
            both.push_back(t);
        } else if (ai == 1) {
            a.push_back(t);
        } else if (bi == 1) {
            b.push_back(t);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(both.begin(), both.end());
    partSum(a);
    partSum(b);
    partSum(both);
    int res = INT_MAX;
    for (int bothCount = 0; bothCount <= both.size(); bothCount++) {
        if (bothCount > k) break;
        int needa = k - bothCount, needb = k - bothCount;
        if (needa > a.size() || needb > b.size()) continue;
        int aval = 0, bval = 0, bothval = 0;
        if (needa > 0) aval = a[needa - 1];
        if (needb > 0) bval = b[needb - 1];
        if (bothCount > 0) bothval = both[bothCount - 1];
        int total = aval + bval + bothval;
        res = min(res, total); 
    }
    if (res == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << res << '\n';
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
