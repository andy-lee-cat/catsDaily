// 459b 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    int mincnt = 0;
    int maxcnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) mincnt++;
        else break;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == a[n - 1]) maxcnt++;
        else break;
    }
    if (a[0] == a[n - 1]) {
        cout << 0 << " " << (long long)n * (n - 1) / 2 << '\n';
        return;
    }
    cout << a[n - 1] - a[0] << " " << (long long)mincnt * maxcnt << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
