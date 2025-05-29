// 1753B 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> cnt(x + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a >= x) continue;
        cnt[a]++;
    }
    for (int i = 0; i < x; i++) {
        cnt[i + 1] += cnt[i] / (i + 1);
        cnt[i] %= i + 1;
        if (cnt[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
