// 1634B 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int bit = x % 2;
    for (long long v : a) 
        bit ^= v % 2; 
    if (bit == y % 2) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
