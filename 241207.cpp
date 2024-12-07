// 600b 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    for (auto val : b) {
        auto it = upper_bound(a.begin(), a.end(), val);
        cout << it - a.begin() << " ";
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
