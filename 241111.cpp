// 271D 1800
// 12:23 30min
#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    string bt;
    cin >> bt;
    auto g = [&](char c) {
        return bt[c - 'a'] == '1';
    };
    int k;
    cin >> k;
    int cnt = 0;
    vector<array<int, 26>> tree;
    vector<bool> ext;
    ext.push_back(true);
    tree.push_back(array<int, 26>{0});
    auto add = [&](char c, int node) -> void {
        c -= 'a';
        if (tree[node][c] == 0) {
            tree[node][c] = tree.size();
            tree.push_back(array<int, 26>{0});
            cnt++;
        }
    };
    int nowk = k;
    for (int i = 0; i < n; i++) {
        nowk = k;
        int now = 0;
        if (!g(s[i]) && nowk == 0) continue;
        for (int j = i; j < n; j++) {
            if (!g(s[j])) {
                if (nowk == 0) break;
                nowk--;
            }
            add(s[j], now);
            now = tree[now][s[j] - 'a'];
        } 
    }
    cout << cnt << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
