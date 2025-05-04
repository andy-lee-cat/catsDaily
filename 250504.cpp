// 1245C 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1000000007 

long long ans[100005];

long long ADD(long long x, long long y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

long long MUL(long long x, long long y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

void init() {
    ans[0] = 1, ans[1] = 1, ans[2] = 2;
    for (int i = 3; i < 100005; i++) {
        ans[i] = ADD(ans[i - 1], ans[i - 2]);
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    long long res = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << '\n';
            return;
        }
        if (s[i] != 'u' && s[i] != 'n') continue;
        char now = s[i];
        int len = 0;
        while (i < n && s[i] == now) {
            i++;
            len++;
        }
        res = MUL(res, ans[len]);
        i--;
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
