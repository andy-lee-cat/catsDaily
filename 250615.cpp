// 1555D 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string s;
vector<vector<int>> presum(6);

string ss[6] = {
    "abc", "acb",
    "bac", "bca",
    "cab", "cba"
};

void init() {
    for (int i = 0; i < 6; i++) {
        presum[i].resize(n + 1);
        presum[i][0] = 0;
        for (int j = 0; j < n; j++) {
            presum[i][j + 1] = presum[i][j] + 
                (s[j] != ss[i][j % 3]);
        }
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    int res = r - l + 1;
    for (int i = 0; i < 6; i++) {
        res = min(res, presum[i][r] - presum[i][l - 1]);
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> n >> t;
    cin >> s;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
