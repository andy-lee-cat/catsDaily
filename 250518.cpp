// 1352F 1500
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    if (n1 == 0) {
        if (n0 != 0) {
            cout << string(n0 + 1, '0') << '\n';
        } else {
            cout << string(n2 + 1, '1') << '\n';
        }
        return;
    }
    string res = "";
    res += "0";
    while (n0--) res += "0";
    n1 -= 1;
    res += "1";
    while (n2--) res += "1";
    bool fg = true;
    while (n1--) {
        if (fg) res += "0";
        else res += "1";
        fg = !fg;
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
