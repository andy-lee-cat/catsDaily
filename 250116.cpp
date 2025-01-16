// 1519D 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) 
        sum += a[i] * b[i];
    long long diff = 0;
    for (int mid = 0; mid < n; mid++) {
        // type 1:
        int l = mid, r = mid;
        long long cur = 0;
        while (l >= 0 && r < n) {
            cur += a[l] * b[r] + a[r] * b[l];
            cur -= a[l] * b[l] + a[r] * b[r];
            diff = max(diff, cur);
            l--, r++;
        }
        // type 2:
        l = mid, r = mid + 1;
        cur = 0;
        while (l >= 0 && r < n) {
            cur += a[l] * b[r] + a[r] * b[l];
            cur -= a[l] * b[l] + a[r] * b[r];
            diff = max(diff, cur);
            l--, r++;
        }
    }
    cout << sum + diff << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
