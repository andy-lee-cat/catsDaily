#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    string s;
    cin >> s;

    int Lcnt = 0;
    for (int i = 0; i < n - 1; i++) 
        if (s[i] == 'L')
            Lcnt++;

    int l = Lcnt, r = Lcnt;
    vector<int> arr;
    arr.push_back(a[l]);
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'L') {
            arr.push_back(a[--l]);
        } else {
            arr.push_back(a[++r]);
        }
    }
    vector<int> res;
    int now = 1;
    for (int i = 0; i < n; i++) {
        now = (now * arr[i]) % m;
        res.push_back(now);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << res[i] << " \n"[i == 0];

}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
