// 1372C 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> b(n);
    int right = 0, wrong = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] == i) b[i] = true, right++;
        else b[i] = false, wrong++;
    }
    if (wrong == 0) {
        cout << "0\n";
        return;
    }

    if (right == 0) {
        cout << "1\n";
        return;
    }

    int l = 0;
    while (l < n && b[l]) l++;
    int r = n - 1;
    while (r >= 0 && b[r]) r--;
    for (int i = l; i <= r; i++) {
        if (b[i]) {
            cout << "2\n";
            return;
        }
    }
    cout << "1\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
