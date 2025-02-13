// 1352B 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    long long n;
    int k;
    cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0) {
        cout << "NO\n";
        return;
    }
    if (n % 2 == 1) {
        if (n - k < 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++)
            cout << "1 ";
        cout << n - k + 1 << '\n';
        return;
    }
    // n % 2 == 0
    if (k % 2 == 0) {
        if (n - k < 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++)
            cout << "1 ";
        cout << n - k + 1 << '\n';
        return;
    }
    if (n - k * 2 < 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < k - 1; i++)
        cout << "2 ";
    cout << n - 2 * (k - 1) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
