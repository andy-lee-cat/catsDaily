// 1623C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    long long l = 0, r = *max_element(h.begin(), h.end()) + 1; 
    auto check = [&](int minv) -> bool {
        vector<long long> add(n);
        for (int i = n - 1; i >= 2; i--) {
            if (h[i] + add[i] < minv) 
                return false;
            
            long long d = min(h[i], h[i] + add[i] - minv);
            d /= 3;
            add[i - 1] += d;
            add[i - 2] += 2 * d;
        }
        for (int i = 1; i >= 0; i--) 
            if (h[i] + add[i] < minv)
                return false;
        return true;
    };
    while (l < r) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m + 1;
        else r = m; 
    }
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
