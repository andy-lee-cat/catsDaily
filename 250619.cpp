// 1486B 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i] >> ys[i];
    
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    if (n % 2 == 1) {
        cout << 1 << '\n';
        return;
    }

    int x0 = xs[n / 2 - 1], x1 = xs[n / 2];
    int y0 = ys[n / 2 - 1], y1 = ys[n / 2];

    long long res = 1ll * (x1 - x0 + 1) * (y1 - y0 + 1);
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
