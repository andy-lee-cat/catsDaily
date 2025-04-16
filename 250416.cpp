// 276D 1700
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bit(long long x, int i) {
    return (x >> i) & 1;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    long long res = 0;
    int i;
    for (i = 62; i >= 0; i--) {
        if (bit(l, i) == 0 && bit(r, i) == 1) {
            break;
        } 
    }
    cout << (1ll << (i + 1)) - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
