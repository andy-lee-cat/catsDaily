// 1931E 1400
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> zero(n);
    vector<int> bit(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int cnt = 0;
        while (a[i] && a[i] % 10 == 0) {
            a[i] /= 10;
            cnt++;
        }
        zero[i] = cnt;
        cnt = 0;
        while (a[i]) {
            a[i] /= 10;
            cnt++;
        }
        bit[i] = cnt;
    }
    sort(zero.begin(), zero.end(), greater<int>());
    int res = accumulate(bit.begin(), bit.end(), 0);
    for (int i = 1; i < n; i += 2) {
        res += zero[i];
    }
    if (res <= m) {
        cout << "Anna\n";
    } else {
        cout << "Sasha\n";
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
