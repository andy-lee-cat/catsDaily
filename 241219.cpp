// 1389B 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

// 没写出来
void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    multiset<int> s;
    int res = a[0];
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        res += a[i];
        s.insert(a[i - 1] + a[i]);
    }
    ans = res;
    for (int i = k; i > 0; i -= 2) {
        // delete a[k] and a[k - 1], add max(s'), s' = s.erase(s.find(a[k - 1] + a[k]))
        s.erase(s.find(a[i - 1] + a[i]));
        res -= a[i] + a[i - 1];
        res += *s.rbegin();
        ans = max(ans, res);
    } 
    cout << ans << '\n';
}

void solve_official() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    int mx = a[0] + a[1];
    int s = 0;
    int res = 0;
    for (int i = 0; i <= k; i++) {
        if (i != n - 1) mx = max(mx, a[i] + a[i + 1]);
        s += a[i];
        if (i % 2 == k % 2) {
            int loop = (k - i) / 2;
            int ans = s + min(loop, z) * mx;
            res = max(res, ans);
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve_official();
    }
    return 0;
}
