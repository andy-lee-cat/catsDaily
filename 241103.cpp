// 377A 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

void solve() {
    // 这个思路是，把有三个墙的格子放入队列，然后取出，更新附近的格子（是否放入队列）
    // 如果没有三个墙的，随便选一个，然后更新附近的格子
    // 但是反例如下（这个样例不会出错，但是表现出了这个思路有问题，在更大范围的数据可能出错
    // .....#.....
    // ...........
    // 第一个#下面的格子按上面的逻辑是可以改成#的，但实际会破坏连通性
    // 下面是一个更加直观的反例
    // ....
    // .#..
    // ..##
    // ..##
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> ws(n);
    for (int i = 0; i < n; i++)
        cin >> ws[i];
    auto get = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        return ws[i][j] == '.' ? 0 : 1;
    };
    auto sum = [&](int i, int j) {
        return get(i - 1, j) + get(i + 1, j) + get(i, j - 1) + get(i, j + 1);
    };
    queue<int> link;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (sum(i, j) == 3 && get(i, j) == 0)
                link.push(i * m + j);
    
    vector<int> nxt = {0, -1, 0, 1, 0};
    int last = 0;
    while (k--) {
        int idx, x, y;
        if (!link.empty()) {
            idx = link.front();
            x = idx / m, y = idx % m;
            link.pop();
        } else {
            for (idx = last; idx < n * m; idx++) {
                if (get(idx / m, idx % m) == 0) {
                    x = idx / m, y = idx % m;
                    last = idx;
                    break;
                }
            }
        }
        ws[x][y] = 'X';
        for (int i = 0; i < 4; i++) {
            int x = idx / m + nxt[i];
            int y = idx % m + nxt[i + 1];
            if (get(x, y) == 0 && sum(x, y) == 3) {
                link.push(x * m + y);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ws[i] << '\n';
}

void solve_dfs() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> ws(n);
    for (int i = 0; i < n; i++)
        cin >> ws[i];
    auto get = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        return ws[i][j] == '.' ? 0 : 1;
    };
    int spare = 0;
    int startx, starty;;
    for (int idx = 0; idx < n * m; idx++) {
        int x = idx / m, y = idx % m;
        if (get(x, y) == 0) {
            spare++;
            startx = x;
            starty = y;
        }
    }
    int dfscnt = spare - k;

    auto dfs = [&](auto&& self, int x, int y) {
        if (dfscnt == 0 || get(x, y) == 1) return;
        ws[x][y] = 'V';
        dfscnt--;
        self(self, x - 1, y);
        self(self, x + 1, y);
        self(self, x, y - 1);
        self(self, x, y + 1);
    };

    dfs(dfs, startx, starty);
    for (int idx = 0; idx < n * m; idx++) {
        int x = idx / m, y = idx % m;
        if (ws[x][y] == 'V') ws[x][y] = '.';
        else if (ws[x][y] == '.') ws[x][y] = 'X';
    }
    for (int i = 0; i < n; i++)
        cout << ws[i] << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve_dfs();
    }
    return 0;
}
