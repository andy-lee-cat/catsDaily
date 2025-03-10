// 295A 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<tuple<int, int, int>> o(m);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        o[i] = {l, r, d};
    }
    vector<tuple<int, int>> q(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        q[i] = {x, y};
    }
    vector<long long> cnts(m + 1);
    for (int i = 0; i < k; i++) {
        auto [x, y] = q[i];
        cnts[x - 1]++;
        cnts[y]--;
    }
    for (int i = 1; i < m; i++)
        cnts[i] += cnts[i - 1];
    
    vector<long long> add(n + 1);
    for (int i = 0; i < m; i++) {
        auto [l, r, d] = o[i];
        add[l - 1] += d * cnts[i];
        add[r] -= d * cnts[i];
    }
    for (int i = 1; i < n; i++)
        add[i] += add[i - 1];
    for (int i = 0; i < n; i++)
        cout << a[i] + add[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
