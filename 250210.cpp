// 1343C 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = (a[0] > 0);
    long long res = 0;
    long long now = a[0];
    for (int i = 1; i < n; i++) {
        if ((a[i] > 0) == flag) {
            now = max(now, a[i]);
        } else {
            res += now;
            now = a[i];
            flag = !flag;
        }
    }
    res += now;
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
