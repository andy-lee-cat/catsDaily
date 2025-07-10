// 1312C 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool allzero;
    do {
        allzero = true;
        bool exist = false;
        for (int i = 0; i < n; i++) {
            int left = a[i] % k;
            if (left != 0 && left != 1) {
                cout << "NO\n";
                return;
            }
            if (left == 1) {
                if (exist) {
                    cout << "NO\n";
                    return;
                } else {
                    exist = true;
                }
            }
            a[i] /= k;
            if (a[i]) allzero = false;
        }
    } while (!allzero);
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
