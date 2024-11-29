// 1358C 1600
// iq题，找规律，最后发现相邻换一条路径sum-1，能换dx*dy次
// 加上最开始最小的那条开始，共1+dx*dy次
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1, dy = y2 - y1;
    cout << 1ll + 1ll * dx * dy << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
