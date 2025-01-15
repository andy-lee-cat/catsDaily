// 1375C 1400
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
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    if (a[0] > a[n - 1]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
