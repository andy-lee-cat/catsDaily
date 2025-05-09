#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int mySqrt(int x) {
    return sqrt(x);
}

void solve() {
    int n;
    cin >> n;
    int x = mySqrt(2 * n - 1);
    int res = x % 2 ? 0 : -1;
    res += x / 2;
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
