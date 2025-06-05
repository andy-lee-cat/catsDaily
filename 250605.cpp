// 1995C 1800
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int cul(long long a0, long long a1, long long p0) {
    // return p0 + log2(loga1(a0))
    
    // check log2(loga1(a0)) is int
    long long temp = a1;
    if (a1 == a0) return p0;
    if (a1 < a0) {
        int op = 0;
        while (a1 < a0) {
            a1 = a1 * a1;
            op++;
        }
        return p0 + op;
    } else {
        int op = 0;
        if (a0 == 1) return 0;
        while (a0 <= a1) {
            a0 = a0 * a0;
            op++;
        }
        return max(0ll, p0 - op + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> ops(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // check 1
    for (int i = 1; i < n; i++) {
        if (a[i] == 1 && a[i - 1] != 1) {
            cout << "-1\n";
            return;
        }
    }
    
    long long res = 0;
    ops[0] = 0;
    for (int i = 1; i < n; i++) {
        ops[i] = cul(a[i - 1], a[i], ops[i - 1]);
        res += ops[i];
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
