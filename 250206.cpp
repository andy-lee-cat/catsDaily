// 1490E 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    int res = 1;
    for (int i = n - 1; i > 0; i--) {
        sum -= a[idx[i]];
        if (sum < a[idx[i]]) 
            break;
        res++;
    }
    cout << res << '\n';
    vector<int> ans(res);
    for (int i = 0; i < res; i++)
        ans[i] = idx[n - 1 - i] + 1;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < res; i++)
        cout << ans[i] << " \n"[i == res - 1]; 
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
