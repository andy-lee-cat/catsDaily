// 1707A 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    string res(n, '0');
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (q >= n) {
        cout << string(n, '1') << '\n';
        return;
    }
    int least = 0;
    int l = 0, r = n + 1;
    for (int i = 0; i < n; i++)
        if (a[i] <= q)
            res[i] = '1', l++;
    least = l;
    while (l < r) {
        int m = l + (r - l) / 2;
        int need = m - least;
        int start = n - 1;
        for (int i = n - 1; need > 0; i--) {
            if (a[i] > q) {
                need--;
                start = i;
            }
        }
        int nowq = q;
        bool ok = true;
        for (int i = start; i < n; i++) {
            if (nowq <= 0) {
                ok = false;
                break;
            }
            if (a[i] > nowq) 
                nowq--;
        }
        if (ok) l = m + 1;
        else r = m;
    }
    int count = l - 1 - least;
    for (int i = n - 1; count > 0; i--) {
        if (a[i] > q) {
            res[i] = '1';
            count--;
        }
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
