// 1285c 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    long long x;
    cin >> x;
    long long resa = 1, resb = x;
    for (int i = 1; i <= 1e6; i++) {
        if (x % i == 0) {
            long long a = i, b = x / i;
            if (__gcd(a, b) == 1) {
                if (max(a, b) < max(resa, resb)) {
                    resa = a;
                    resb = b;
                }
            }
        }
    }
    cout << resa << ' ' << resb << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
