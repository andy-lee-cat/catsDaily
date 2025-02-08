// 1401C 1400
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
    int minn = *min_element(a.begin(), a.end());
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;
    stable_sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    for (int i = 0; i < n; i++) {
        if (a[i] != a[idx[i]] && a[i] % minn != 0) {
            cout << "NO\n";
            return;
        }
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
