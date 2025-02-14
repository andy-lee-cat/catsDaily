// 1915E 1300
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long now = 0;
    set<long long> s;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) a[i] = -a[i];

        now += a[i];
        if (s.find(now) != s.end()) {
            cout << "YES\n";
            return;
        }
        s.insert(now);
    }
    cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
