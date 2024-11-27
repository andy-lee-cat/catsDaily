// 1363c 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 1) {
        cout << "Ayush\n";
        return;
    }
    int in = g[x].size();
    if (in == 1) {
        cout << "Ayush\n";
    } else {
        cout << (n % 2 == 0 ? "Ayush" : "Ashish") << '\n';
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
