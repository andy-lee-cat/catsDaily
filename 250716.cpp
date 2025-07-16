// 1771B 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> lim(n, n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        lim[x] = min(lim[x], y); 
    }
    long long res = 0;
    int range = n;
    for (int i = n - 1; i >= 0; i--) {
        range = min(lim[i], range);
        res += range - i;
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
