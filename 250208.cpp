// 433B 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int m;
    cin >> m;
    vector<int> u(v);
    sort(u.begin(), u.end());
    vector<long long> p1(n + 1), p2(n + 1);
    for (int i = 0; i < n; i++) {
        p1[i + 1] = p1[i] + v[i];
        p2[i + 1] = p2[i] + u[i];
    }
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--, r--;
        if (type == 1) {
            cout << p1[r + 1] - p1[l] << '\n';
        } else {
            cout << p2[r + 1] - p2[l] << '\n';
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
