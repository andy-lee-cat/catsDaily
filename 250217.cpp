// 816B 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<int, int>> lr(n);
    for (int i = 0; i < n; i++) 
        cin >> lr[i].first >> lr[i].second;
    vector<int> ps(2e5 + 6);
    for (int i = 0; i < n; i++) {
        ps[lr[i].first]++;
        ps[lr[i].second + 1]--;
    }
    for (int i = 1; i < 2e5 + 6; i++)
        ps[i] += ps[i - 1];
    vector<int> cnt(2e5 + 6);
    for (int i = 1; i < 2e5 + 6; i++) {
        if (ps[i] >= k) cnt[i] = 1;
        cnt[i] += cnt[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l - 1] << '\n';
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
