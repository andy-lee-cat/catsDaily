// 1362C 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<unsigned long long> a(63);
    a[0] = 1;
    for (int i = 1; i < 63; i++) {
        a[i] = a[i - 1] * 2 + 1;
    }
    long long res = 0;
    for (int i = 0; n > 0; n /= 2, i++) {
        if (n % 2) res += a[i];
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
