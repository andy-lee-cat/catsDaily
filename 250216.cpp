// 1363A 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    if (odd == 0) {
        cout << "No\n";
        return;
    }
    if (even == 0 && x % 2 == 0) {
        cout << "No\n";
        return;
    }
    int res = odd % 2 == 0 ? odd - 1 : odd;
    if (res + even >= x) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
