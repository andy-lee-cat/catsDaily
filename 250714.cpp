// 1462D 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = n; i >= 1; i--) {
        if (sum % i != 0) continue;
        int partsum = sum / i;
        int now = 0;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (now < partsum) now += a[j];
            if (now > partsum) {
                flag = false;
                break;
            } else if (now == partsum) {
                now = 0;
            }
        }
        if (flag) {
            cout << n - i << endl;
            return;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
