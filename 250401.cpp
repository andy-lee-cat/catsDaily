// 977D 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    set<long long> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> ops(n);
    int start = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 != 0 || !s.count(a[i] / 2)) &&
            (!s.count(a[i] * 3))) {
            start = i;
            break;
        }   
    }
    vector<long long> res(n);
    res[0] = a[start];
    long long now = a[start];
    for (int i = 1; i < n; i++) {
        if (s.count(now * 2)) {
            now *= 2;
            res[i] = now;
        } else {
            now /= 3;
            res[i] = now;
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
