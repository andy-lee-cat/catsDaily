// 977F 1700
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int get_last(vector<vector<int>>& g) {
    int n = g.size();
    queue<int> q;
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        for (int v : g[i])
            in[v]++;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            q.push(i);
    int last = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int u = q.front(); q.pop();
            last = u;
            for (int v : g[u]) 
                q.push(v);
        }
    }
    return last;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> g(n, -1);
    map<int, int> idx;
    for (int i = 0; i < n; i++) {
        auto it = idx.find(a[i] - 1);
        if (it != idx.end()) {
            g[i] = it->second;
        }
        idx[a[i]] = i;
    }
    vector<bool> vis(n);
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++)
        if (g[i] != -1)
            tree[g[i]].push_back(i);
    int start = get_last(tree);

    vector<int> ans;
    int now = start;
    while (now != -1) {
        ans.push_back(now);
        now = g[now];
    }
    reverse(ans.begin(), ans.end());
    int res = ans.size();
    cout << res << '\n';
    for (int i = 0; i < res; i++)
        cout << ans[i] + 1 << " \n"[i == res - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
