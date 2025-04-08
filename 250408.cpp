// 1701C 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include <set>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> t(n);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) 
        t[a[i] - 1]++;
    sort(t.begin(), t.end());
    int l = 0, r = t.back() + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        long long bg = 0, sm = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] > mid) bg += t[i] - mid;
            else sm += (mid - t[i]) / 2;
        }
        if (sm < bg) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << '\n'; 
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
