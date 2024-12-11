// 1328b 1300
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long f(int x) {
    return 1ll * (x - 1) * (x - 2) / 2;
}
// aaaabb
// x = 2
// cnt = 0 = (x - 2) * (x - 1) / 2
// aaabab
// x = 3
// cnt = 1 = (x - 2) * (x - 1) / 2

void solve() {
    int n, k;
    cin >> n >> k;
    k--;
    int l = 2, r = n + 1;
    int m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (f(m) <= k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    int bl = l - 1;
    long long cnt = 1ll * (bl - 2) * (bl - 1) / 2;
    int br = k - cnt + 1;
    string res(n, 'a');
    res[n - bl] = 'b';
    res[n - br] = 'b';
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
