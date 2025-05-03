// 1622C 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

long long mdiv(long long a, long long b) {
    long long res = a / b;
    if (a % b != 0) {
        res++;
    }
    return res;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long diff = sum - k;
    if (diff <= 0) {
        cout << 0 << '\n';
        return;
    }
    if (n == 1) {
        cout << diff << '\n';
        return;
    }
    if (diff == 1) {
        cout << 1 << '\n';
        return;
    }
    long long res = 1e10;
    for (int i = n - 1; i >= 1; i--) {
        int len = n - i + 1;
        diff -= a[i] - a[0];
        if (diff > 0) {
            res = min(res, mdiv(diff, len) + len - 1);
        } else {
            res = min(res, (long long)len - 1);
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
