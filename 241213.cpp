// 1349A 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long __lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long gcd = __gcd(a[0], a[1]);
    long long res = __lcm(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        res = __gcd(res, __lcm(a[i], gcd));
        gcd = __gcd(gcd, a[i]);
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
