// 1714E 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            a[i] += a[i] % 10;
        }
        int mod = a[i] % 10;
        if (mod == 0) {
            b.push_back(a[i]);
            continue;
        }
        if (mod == 4) {
            a[i] += 18;
        } else if (mod == 6) {
            a[i] += 6;
        } else if (mod == 8) {
            a[i] += 14;
        }
        a[i] /= 10;
        a[i] %= 2;
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) {
            cout << "NO\n";
            return;
        }
    }
    if (b.size() != 0 && b.size() != n) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < (int)b.size() - 1; i++) {
        if (b[i] != b[i + 1]) {
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
