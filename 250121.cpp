// 1380C 1400
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
    sort(a.begin(), a.end(), greater<int>());
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x) {
            res++;
            continue;
        }
        cnt++;
        if (cnt * a[i] >= x) {
            res++;
            cnt = 0;
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
