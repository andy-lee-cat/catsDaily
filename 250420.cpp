// 1603B 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    // find n, n % x == y % n
    /*
    case 1: x == y
        n = x
    case 2: x > y
        n = x + y
    case 3: x < y
        d = (y - x) % x
        if d % 2 == 0
            n = y - d / 2
        else
            not exist
    */
    long long n;
    if (x == y) {
        n = x;
    } else if (x > y) {
        n = x + y;
    } else {
        int d = (y - x) % x;
        if (d % 2 == 0) {
            n = y - d / 2;
        } else {
            n = -1;
        }
    }
    if (n == -1) {
        cout << n << '\n';
    } else if (n % x != y % n) {
        cout << -1 << '\n';
    } else {
        cout << n << '\n';
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
