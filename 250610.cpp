// 839C 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> g;

double dfs(int u, int p) {
	int cnt = 0;
	double sum = 0;
	for (int v : g[u]) {
		if (v == p) continue;
		sum += dfs(v, u);
		cnt++;
	}
	if (cnt == 0) return 0;
	return 1.0 + sum / cnt;
}

void solve() {
	int n;
	cin >> n;
	g.clear();
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
    }
    double res = dfs(0, -1);
	printf("%.8lf\n", res);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
