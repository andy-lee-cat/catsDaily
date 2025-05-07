// 165B 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> powk;
    long long now = 1;
    while (now <= n) {
        powk.push_back(now);
        now *= k;
    }
    int l = 1, r = n + 1;
    auto can = [&](int v) -> bool {
        long long sum = 0;
        for (auto pk : powk) {
            sum += v / pk;
        }
        return sum >= n;
    };
    while (l < r) {
        int m = l + (r - l) / 2;
        if (can(m)) {
            r = m;
        } else {
            l = m + 1;
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
