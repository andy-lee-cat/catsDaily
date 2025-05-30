// 1359C 1700
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int h, c, t; // c <= t <= h
    cin >> h >> c >> t;
    // case1: hc = cc
    double diff1 = abs(t * 2 - h - c);
    if (diff1 == 0) {
        cout << 2 << '\n';
        return;
    }
    diff1 /= 2;
    // case2: hc = cc + 1
    int mid = h + c;
    // (h * 1 + mid * n) / (2n + 1) => t
    // h + mid * n = t * (2n + 1)
    // h - t = n * (2t - mid)
    int n, mod;
    if (2 * t - mid <= 0) {
        cout << 2 << '\n';
        return;
    }
    n = (h - t) / (2 * t - mid);
    mod = (h - t) % (2 * t - mid);
    if (mod == 0) {
        cout << 2 * n + 1 << '\n';
        return;
    }
    // case2.1: n
    double diff21 = abs((h * 1.0 + (double)mid * n) / (2 * n + 1) - t);
    // case2.2: n + 1
    n += 1;
    double diff22 = abs((h * 1.0 + (double)mid * n) / (2 * n + 1) - t);
    if (diff21 <= diff22 && diff21 < diff1) {
        cout << 2 * n - 1 << '\n';
    } else if (diff22 < diff21 && diff22 < diff1) {
        cout << 2 * n + 1 << '\n';
    } else {
        cout << 2 << '\n';
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
