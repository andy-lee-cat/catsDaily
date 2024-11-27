// 466A 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (m * a <= b) {
        cout << n * a << '\n';  
    } else {
        int res = 0;
        res += (n / m) * b;
        res += min((n % m) * a, b);
        cout << res << '\n';
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
