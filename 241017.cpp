// 478c 1800
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    vector<long long> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[2] > (a[0] + a[1]) * 2) {
        cout << a[0] + a[1] << '\n';
        return;
    }
    cout << (a[0] + a[1] + a[2]) / 3 << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
