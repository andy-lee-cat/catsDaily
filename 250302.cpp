// 1399C 1200
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
    vector<int> cnts(n + 1, 0);
    for (int i = 0; i < n; i++)
        cnts[a[i]]++;
    int res = 0;
    for (int s = 2; s <= 2 * n; s++) {
        int cnt = 0;
        for (int i = 1; i < (s + 1) / 2; i++)
            if (s - i <= n)
                cnt += min(cnts[i], cnts[s - i]);
        if (s % 2 == 0)
            cnt += cnts[s / 2] / 2;
        res = max(res, cnt);
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
