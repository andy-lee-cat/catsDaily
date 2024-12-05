// 489B 1200
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
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int idxa = 0, idxb = 0;
    int res = 0;
    while (idxa < n && idxb < m) {
        if (abs(a[idxa] - b[idxb]) <= 1) {
            res++;
            idxa++;
            idxb++;
        } else {
            if (a[idxa] < b[idxb])
                idxa++;
            else
                idxb++;
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
