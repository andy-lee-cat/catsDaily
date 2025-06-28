// 1295C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<bool> exist(26);
    for (char c : s)
        exist[c - 'a'] = true;
    for (char c : t) {
        if (!exist[c - 'a']) {
            cout << "-1\n";
            return;
        }
    }

    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); i++)
        pos[s[i] - 'a'].push_back(i);
    int res = 0;
    int idx = s.size() - 1;
    for (char c : t) {
        c -= 'a';
        // 这里可以用dp在线性时间内存好所有nxt
        auto it = upper_bound(pos[c].begin(), pos[c].end(), idx);
        if (it == pos[c].end()) {
            res++;
            idx = pos[c][0];
        } else {
            idx = *it;
        }
    }
    cout << res << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
