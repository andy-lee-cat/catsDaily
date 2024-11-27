// 520B 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << n - m << '\n';
        return;
    }
    int res = 0;
    while (n < m) {
        if (m % 2 == 0) {
            m /= 2;
            res++;
        } else {
            m = (m + 1) / 2;
            res += 2;
        }
    }
    res += n - m;
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
