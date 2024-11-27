// 451b 1300
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
    vector<bool> d(n, false);
    for (int i = 1; i < n; i++) 
        d[i] = a[i] - a[i - 1] > 0;
    // 1111000111
    int first = -1;
    for (int i = 1; i < n; i++) {
        if (!d[i]) {
            first = i;
            break;
        }
    }
    int last = n;
    for (int i = n - 1; i >= 0; i--) {
        if (!d[i]) {
            last = i;
            break;
        }
    }
    if (first == -1) {
        cout << "yes\n";
        cout << "1 1\n";
        return;
    }
    for (int i = first; i < last; i++) {
        if (d[i]) {
            cout << "no\n";
            return;
        }
    }
    int l = first == 1 ? 0 : a[first - 2];
    int r = last == n - 1 ? 1e9 + 1 : a[last + 1];
    if (l > a[last] || r < a[first - 1]) {
        cout << "no\n";
        return;
    } else {
        cout << "yes\n";
        cout << first << ' ' << last + 1 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
