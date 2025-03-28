// 1572A 1800
// 可以用加权图最长路径来做，如果a->b,学了a才能学b
// a>b, 那么a->b的边权为1，否则为0
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int ct = 0;
bool test = false;

void printG(vector<vector<int>>& g) {
    cout << endl;
    for (int i = 1; i < g.size(); i++) {
        cout << i << ": ";
        for (int v : g[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

void solve() {
    ct++;
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        g[i].resize(k);
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            g[i][j] = x;
        }
    }

    if (test && ct == 2041) {
        printG(g);
    }

    // check no cycle
    vector<int> in(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            in[v]++;
        }
    }
    vector<bool> vis(n + 1);
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            stk.push(i);
            vis[i] = true;
        }
    }
    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
        for (int v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                stk.push(v);
                vis[v] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!test)
            cout << "-1" << '\n';
            return;
        }
    }
    vector<vector<int>> gg(n + 1);  // 指向后续课程
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            gg[v].push_back(i);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        in[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int v : gg[i])
            in[v]++;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);
    
    vector<int> wait;
    while (!wait.empty() || !q.empty()) {
        if (q.empty()) {
            res++;
            sort(wait.begin(), wait.end(), greater<int>());
            while (!wait.empty()) {
                int u = wait.back(); wait.pop_back();
                q.push(u);
            }
        }
        int u = q.top(); q.pop();
        for (int v : gg[u]) {
            in[v]--;
            if (in[v] == 0) {
                if (v > u)
                    q.push(v);
                else
                    wait.push_back(v);
            }
        }
    }
    if (!test)
    cout << 1 + res << '\n'; 
}

int main() {
    int t = 1;
    cin >> t;
    if (t == 20000) {
        // test = true;
    }
    while (t--) {
        solve();
    }
    return 0;
}
