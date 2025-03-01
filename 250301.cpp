// 1692G 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<bool> large(n - 1, false);
    for (int i = 0; i < n - 1; i++)
        if (a[i] < a[i + 1] * 2) 
            large[i] = true;
    int cnt = 0;
    for (int i = 0; i < k; i++)
        if (large[i])
            cnt++;
    int res = 0;
    if (cnt == k) res++;
    for (int r = k; r < n - 1; r++) {
        if (large[r]) cnt++;
        if (large[r - k]) cnt--;
        if (cnt == k) res++;
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
