// 1458A 1600
// 12:02 18min 2WA
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    long long mina = *min_element(a.begin(), a.end());
    long long gcd = 0;
    for (int i = 0; i < n; i++) 
        gcd = __gcd(gcd, a[i] - mina);
    for (int i = 0; i < m; i++)
        cout << __gcd(gcd, mina + b[i]) << " \n"[i == m - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
