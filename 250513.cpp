// 1503A 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1 || s[0] == '0' || s.back() == '0') {
        cout << "NO\n";
        return;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            cnt0++;
    cnt1 = n - cnt0;
    if (cnt0 % 2 == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string a(n, '0'), b(n, '0');
    int ct = 0;
    bool sp = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ct++;
            if (ct <= cnt1 / 2) {
                a[i] = b[i] = '(';
            } else {
                a[i] = b[i] = ')';
            }
        } else {
            a[i] = '('; b[i] = ')';
            if (sp) swap(a[i], b[i]);
            sp = !sp;
        }
    }
    cout << a << '\n' << b << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
