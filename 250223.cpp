// 1328C 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string r1(n, '0'), r2(n, '0');
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            r1[i] = '1';
            r2[i] = '1';
            if (flag) {
                r1[i] = '0';
                r2[i] = '2';
            }
        } else if (s[i] == '1') {
            if (!flag) {
                r1[i] = '1';
                r2[i] = '0';
                flag = true;
            } else {
                r1[i] = '0';
                r2[i] = '1';
            }
        } else if (s[i] == '0') {
            r1[i] = '0';
            r2[i] = '0';
        }
    }
    cout << r1 << '\n';
    cout << r2 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
