// 1515C 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j) -> bool {
        return a[i] < a[j];
    });
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[idx[i]] = (i % m) + 1;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
