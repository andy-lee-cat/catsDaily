// 1343D 1700
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // map<int, int> cnts;
    int MAX = 2 * k + 5;
    vector<int> cnts(MAX);
    for (int i = 0; i < n / 2; i++) 
        cnts[a[i] + a[n - 1 - i]]++;
    
    vector<int> presum(MAX);
    for (int i = 0; i < n / 2; i++) {
        int minv = min(a[i], a[n - 1 - i]);
        int maxv = max(a[i], a[n - 1 - i]);
        int l = minv + 1;
        int r = maxv + k;
        presum[l]++;
        presum[r + 1]--;
    }
    for (int i = 1; i < MAX; i++)
        presum[i] += presum[i - 1];
    // [l, r] sum <-> presum[r] - presum[l - 1]
    int res = 2 * n;
    for (int x = 2; x <= 2 * k; x++) {
        // moveX means the cnt of pairs which need move X
        int move0 = cnts[x];
        int move1 = presum[x] - move0;
        int move2 = n / 2 - move0 - move1;
        res = min(res, move1 + 2 * move2);
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
