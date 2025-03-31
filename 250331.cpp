// 295B 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    vector<int> o(n);
    for (int i = 0; i < n; i++) {
        cin >> o[i];
        o[i]--;
    }
    reverse(o.begin(), o.end());

    long long res = 0;
    vector<long long> ans(n);
    for (int i = 0; i < n; i++) {
        res = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                g[o[j]][o[k]] = min(
                    g[o[j]][o[k]],
                    g[o[j]][o[i]] + g[o[i]][o[k]]
                );
                if (j != k && j <= i && k <= i) 
                    res += g[o[j]][o[k]];
            }
        }
        ans[n - i - 1] = res;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
