// 242C 1800
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

void solve() {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int n;
    cin >> n;
    // 其实可以直接map<pair<int, int>, bool> 
    map<int, map<int, bool>> mp;
    while (n--) {
        int r, x, y;
        cin >> r >> x >> y;
        for (int i = x; i <= y; i++)
            mp[r].insert({i, false});
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    int cnt = 0;
    vector<int> dnxt = {1, -1, 0};
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front(); q.pop();
            if (x == ex && y == ey) {
                cout << cnt << endl;
                return;
            }
            for (int dx : dnxt) {
                for (int dy : dnxt) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (mp.find(nx) != mp.end() && mp[nx].find(ny) != mp[nx].end() && !mp[nx][ny]) {
                        mp[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cnt++;
    }
    cout << -1 << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
