// 1400C 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int x;
    cin >> x;

    string w(n, '1');
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i - x >= 0) w[i - x] = '0';
            if (i + x < n) w[i + x] = '0';
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if ((i - x >= 0 && w[i - x] == '1') ||
                (i + x < n && w[i + x] == '1')) {
                continue;
            } else {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << w << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
