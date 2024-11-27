// 1396B 1800
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxval = 0;
    int sumval = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sumval += a[i];
        maxval = max(maxval, a[i]);
    }
    int left = sumval - maxval;
    if (maxval > left) {
        // first
        cout << "T\n";
    } else {
        int ans = left - maxval;
        if (ans % 2 == 0) {
            // second
            cout << "HL\n";
        } else {
            // first
            cout << "T\n";
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
