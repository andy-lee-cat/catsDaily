// 1385D 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto allSame = [&](int idx, int len, char c) -> int {
        int cnt = 0;
        for (int i = idx; i < idx + len; i++) 
            if (s[i] != c)
                cnt++;
        return cnt;
    };
    auto allGood = [&](auto &&self, int idx, int len, char c) -> int {
        int res = INT_MAX;
        if (len == 1) return c == s[idx] ? 0 : 1;
        res = min(res, allSame(idx, len / 2, c) + self(self, idx + len / 2, len / 2, c + 1));
        res = min(res, allSame(idx + len / 2, len / 2, c) + self(self, idx, len / 2, c + 1));
        return res;
    };
    cout << allGood(allGood, 0, n, 'a') << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
