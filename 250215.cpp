// 1989C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // 1 1
    // -1 -1
    int m1 = 0, m2 = 0;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) m1 += a[i];
        else if (b[i] > a[i]) m2 += b[i];
        else {
            // a[i] == b[i];
            if (a[i] == 1) {
                m1 += 1;
                diff++;
            } else if (a[i] == -1) {
                m2 -= 1;
                diff++;
            }
        }
    } 
    if (m1 > m2) swap(m1, m2);

    if (m1 + 2 * diff < m2) cout << m1 + diff << '\n';
    else {
        int sum = m1 + m2;
        if (sum < 0) cout << (sum - 1) / 2 << '\n';
        else cout << sum / 2 << '\n';
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
