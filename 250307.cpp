// 1401D 1800
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int m;
    cin >> m;
    vector<long long> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    
    sort(p.begin(), p.end());
    if (m <= n - 1) {
        reverse(p.begin(), p.end());
        p.resize(n - 1);
        for (int i = m; i < n - 1; i++)
            p[i] = 1;
    } else {
        for (int i = n - 1; i < m; i++) {
            p[n - 2] = p[n - 2] * p[i] % MOD;
        }
        p.resize(n - 1);
        // 不能sort，MOD取模前sort可以，MOD后sort就打乱了
        // sort(p.begin(), p.end(), greater<long long>());
        reverse(p.begin(), p.end());
    }

    vector<long long> cnts(n);
    auto dfs = [&](auto &&self, int u, int p) -> void {
        int cnt = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            self(self, v, u);
            cnt += cnts[v];
        }
        cnts[u] = cnt;
    };

    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        cnts[i] = (n - cnts[i]) * cnts[i];
    }
    sort(cnts.begin(), cnts.end(), greater<long long>());

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + cnts[i] % MOD * p[i] % MOD) % MOD;
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
