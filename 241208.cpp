// 550A 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (s.find("AB") == string::npos || s.find("BA") == string::npos) {
        cout << "NO" << endl;
        return;
    }
    int posab = -1, posba = -1;
    // ab <-   -> ba
    // pos = pos(a)
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            posab = i + 1;
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'B' && s[i + 1] == 'A') {
            posba = i;
            break;
        }
    }
    if (posab < posba) {
        cout << "YES" << endl;
        return;
    }
    // ba <-   -> ab
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'B' && s[i + 1] == 'A') {
            posba = i + 1;
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            posab = i;
            break;
        }
    }
    if (posab > posba) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
