// 1837D 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = count(s.begin(), s.end(), '(');
    if (left + left != n) {
        cout << -1 << '\n';
        return;
    }
    int stk = 0;
    char stktype = 'x';
    int color = 0;
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        if (s[i] != stktype) {
            if (stk == 0) {
                color++;
                stktype = s[i];
                stk++;
            } else {
                stk--;
            }
        } else {
            stk++;
        }
        colors[i] = color;
    }
    if (color == 1) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) 
            cout << 1 << " \n"[i == n - 1];
    } else {
        cout << 2 << '\n';
        for (int i = 0; i < n; i++) {
            cout << (colors[i] % 2 == 1 ? 1 : 2) << " \n"[i == n - 1];
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
