// 1354B 1200 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 3 + 9 + 27 + 81 = 120
// 163 - 120 = 43
// 43 / 27 = 1 ...... 16
// 12123

void solve() {
    int n;
    string s;
    cin >> s;
    n = s.length();
    vector<int> a(4);
    int l = 0, r = 0;
    auto judge = [&] () {
        return a[1] && a[2] && a[3];
    };
    while (!judge() && r < n) {
        a[s[r] - '0']++;
        r++;
    }
    if (!judge()) {
        cout << 0 << '\n';
        return;
    }
    while (judge()) {
        a[s[l] - '0']--;
        l++;
    }
    int res = r - l + 1;
    // (r - 1) - (l - 1) + 1
    for (; l < r; ){
        while (!judge() && r < n) {
            a[s[r] - '0']++;
            r++;
        }
        if (judge()) {
            res = min(res, r - l);
        }
        a[s[l] - '0']--;
        l++;
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
