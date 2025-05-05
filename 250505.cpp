// 1355D 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    if (n * 2 > s) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) {
            cout << "2 ";
            s -= 2;
        }
        cout << s << '\n';
        cout << "1\n";
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
