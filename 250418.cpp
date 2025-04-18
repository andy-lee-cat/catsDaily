// 1856C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    // 这个思路是错的，分成几个区间单独考虑
    // 后面的区间可能加到一定值了，和前面区间可以作用了
    int n, k;
    cin >> n >> k;
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    
    vector<vector<int>> as;
    as.push_back({in[0]});
    for (int i = 1; i < n; i++) {
        if (in[i] >= as.back().back()) {
            as.back().push_back(in[i]);
        } else {
            as.push_back({in[i]});
        }
    }
    int res = *max_element(in.begin(), in.end());
    for (auto& a : as) {
        for (int start = a.size() - 2; start >= 0; start--) { 
            int tempk = k;
            int val = a[start + 1];
            for (int i = start; i >= 0; i--) {
                int diff = val + 1 - a[i];
                if (diff <= tempk) {
                    val++;
                    tempk -= diff;
                    res = max(res, val);
                } else {
                    break;
                }
            }
        }
    }
    cout << res << '\n';
}

void solve2() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = *max_element(a.begin(), a.end());
    int r = l + k + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        bool ok = false;
        if (m <= a[n - 1]) ok = true;
        for (int i = 0; i < n - 1; i++) {
            int val = m;
            bool valid = true;
            long long need = val - a[i];
            if (need == 0) {
                ok = true;
                break;
            }
            for (int j = i + 1; j < n; j++) {
                val--;
                if (val <= a[j]) break;
                need += val - a[j];
                if (j == n - 1) valid = false;
            }
            if (valid && need <= k) {
                ok = true;
                break;
            }
        }
        if (ok) l = m + 1;
        else r = m;
    }
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}
