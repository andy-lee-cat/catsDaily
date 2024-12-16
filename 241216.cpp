// 550C 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    // 1
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' || s[i] == '8') {
            cout << "YES\n";
            cout << s[i] << '\n';
            return;
        }
    }
    // 2
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int test = (s[i] - '0') * 10 + s[j] - '0';
            if (test % 8 == 0) {
                cout << "YES\n";
                cout << test << '\n';
                return;
            }
        }
    }
    // 3
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int test = (s[i] - '0') * 100 +
                            (s[j] - '0') * 10 +
                            s[k] - '0';
                if (test % 8 == 0) {
                    cout << "YES\n";
                    cout << test << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
