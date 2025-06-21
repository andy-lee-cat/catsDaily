// 1490F 1500
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> tempcnts;
    vector<int> cnts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tempcnts[x]++;
    } 
    for (auto [k, v] : tempcnts) {
        cnts.push_back(v);
    }
    sort(cnts.begin(), cnts.end());
    int m = cnts.size();
    vector<long long> preSum(m + 1, 0);
    for (int i = 1; i <= m; i++) 
        preSum[i] = preSum[i - 1] + cnts[i - 1];
    long long total = preSum[m];
    long long res = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        long long left = preSum[i];
        long long right = preSum[m] - preSum[i + 1];
        long long leftres = left;
        long long rightres = right - 1ll * cnts[i] * (m - 1 - i);
        res = min(res, leftres + rightres);
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
