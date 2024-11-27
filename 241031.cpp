// 489C 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    if (n == 1 && s == 0) {
        cout << "0 0\n";
        return;
    }
    int temps = s;
    if (s > 9 * n || s < 1) {
        cout << -1;
    } else {
        for (int i = 0; i < n; i++) {
            int pt = max(0, s - (n - 1 - i) * 9);
            if (i == 0) pt = max(1, pt);
            s -= pt;
            cout << pt;
        }
    } 
    s = temps;

    if (s > 9 * n || s < 1) {
        cout << " -1\n";
        return;
    }
    cout << ' ';
    for (int i = 0; i < n; i++) {
        int pt = min(9, s);
        s -= pt;
        cout << pt;
    }
    cout << " \n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
