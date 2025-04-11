// 1329A 1800
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    for (int i = 0; i < m; i++)
        cin >> l[i];
    
    long long sum = accumulate(l.begin(), l.end(), 0LL);
    if (sum < n) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < m; i++) {
        if (i + l[i] > n) {
            cout << -1 << '\n';
            return;
        }
    }

    long long diff = sum - n;
    vector<int> ans(m);
    for (int i = 1; i < m; i++) {
        if (diff == 0) {
            ans[i] = ans[i - 1] + l[i - 1];
        } else {
            long long left = min(diff, (long long)l[i - 1] - 1);
            ans[i] = ans[i - 1] + l[i - 1] - left;
            diff -= left;
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] + 1 << " \n"[i == m - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
