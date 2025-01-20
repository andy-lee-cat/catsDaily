// 1305C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int power(int a, int n, int m) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), cnt(m);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    if (n > m) {
        cout << 0 << '\n';
        return;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        a[i] %= m;
    
    vector<int> res(m, 0);
    cnt[a[0]]++;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[(a[i] - j + m) % m] += cnt[j];
        }
        cnt[a[i]]++;
    }
    int ans = 1;
    for (int i = 0; i < m; i++) {
        ans = ans * power(i, res[i], m) % m;
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
