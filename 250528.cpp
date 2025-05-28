// 1095C 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << "NO\n";
        return;
    }
    int bit = 0;
    while ((1 << bit) <= n) bit++;
    bit--;
    vector<int> ans;
    while (true) {
        // try dec (1<<bit)
        if (n - (1 << bit) < k - 1) {
            bit--;
            continue;
        } else {
            ans.push_back(1 << bit);
            n -= (1 << bit);
            k--;
        }

        if (k == 0 && n != 0) {
            cout << "NO\n";
            return;
        }
        if (k == 0 && n == 0) {
            break;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
