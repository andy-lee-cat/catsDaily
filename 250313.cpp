// 1365D 1700
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    auto get = [&](int i, int j) -> char {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return '#';
        return maze[i][j];
    };
    auto block = [&](int i, int j) -> bool {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return true;
        if (maze[i][j] == 'B')
            return true;
        if (maze[i][j] == 'G')
            return false;
        maze[i][j] = '#';
        return true;
    };

    vector<int> dir = {0, 1, 0, -1, 0};
    int good_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k], y = j + dir[k + 1];
                    if (!block(x, y)) {
                        cout << "No\n";
                        return;
                    }
                }
            } else if (maze[i][j] == 'G') {
                good_cnt++;
            }
        }
    }

    vector<bool> vis(n * m);
    auto dfs = [&](auto &&self, int i, int j) {
        if (get(i, j) == '#') return;
        if (vis[i * m + j]) return;
        vis[i * m + j] = true;
        if (get(i, j) == 'G') good_cnt--;
        for (int k = 0; k < 4; k++)
            self(self, i + dir[k], j + dir[k + 1]);
    };

    dfs(dfs, n - 1, m - 1);
    if (good_cnt == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
