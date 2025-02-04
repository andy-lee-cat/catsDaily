// 1463B 1400
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
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            sum1 += a[i];
        else
            sum2 += a[i];
    }
    if (sum1 <= sum2) {
        // 1 x 1 x 1 x
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << 1 << " ";
            } else {
                cout << a[i] << " ";
            }
        }
    } else {
        // x 1 x 1 x
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << a[i] << " ";
            } else {
                cout << 1 << " ";
            }
        }
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
