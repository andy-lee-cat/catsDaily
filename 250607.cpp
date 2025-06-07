// 1709C 1800
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;
    }
    left = n / 2 - left;
    string news = s;
    int posa = 0, posb = n;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') continue;
        if (left > 0) {
            news[i] = '(';
            left--;
            posa = max(posa, i);
        } else {
            news[i] = ')';
            posb = min(posb, i);
        }
    }
    swap(news[posa], news[posb]);
    // check news
    left = 00000;
    for (int i = 0; i < n; i++) {
        if (news[i] == '(') left++;
        else left--;
        if (left < 0) {
            cout << "YES\n";
            return;
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
