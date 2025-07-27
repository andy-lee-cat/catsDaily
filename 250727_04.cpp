// 1407C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int maxidx = 1;
    for (int i = 2; i <= n; i++) {
        cout << "? " << maxidx << " " << i << endl;
        cout << "? " << i << " " << maxidx << endl;
        int res1, res2; 
        cin >> res1 >> res2;
        if (res1 < res2) {
            a[i] = res2;
        } else {
            a[maxidx] = res1;
            maxidx = i;
        }
    }
    a[maxidx] = n;
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
