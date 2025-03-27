// 1516B 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int xor_sum = 0;
    for (int i = 0; i < n; i++)
        xor_sum ^= a[i];
    if (xor_sum == 0) {
        cout << "YES\n";
        return;
    }
    int l, r;
    int sum = 0;
    for (l = 0; l < n; l++) {
        sum ^= a[l];
        if (sum == xor_sum) break;
    }
    sum = 0;
    for (r = n - 1; r >= 0; r--) {
        sum ^= a[r];
        if (sum == xor_sum) break;
    }
    if (l < r - 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
