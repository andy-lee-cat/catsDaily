// 1348C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// aabbc
// ab abc

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string res;
    res = "";
    vector<int> cnt(26);
    for (char c : s) 
        cnt[c - 'a']++;

    // 这个思路是错的
    // bool ok = true;
    // for (int i = 0; i < 26; i++) {
    //     if (cnt[i] % k != 0) {
    //         ok = false;
    //         break;
    //     }
    // }

    // if (ok) {
    //     for (int i = 0; i < 26; i++) {
    //         res += string(cnt[i] / k, 'a' + i);
    //     }
    //     cout << res << '\n';
    //     return;
    // }

    // 先确保不是空
    for (int i = 0; i < 26; i++) {
        if (!cnt[i]) continue;
        int sum = 0;
        if (cnt[i] < k) {
            // 单一个下一个字母 x
            // 单一个第k个字母
            sum += cnt[i];
            for (int j = i + 1; j < 26; j++) {
                sum += cnt[j];
                if (sum >= k) {
                    cout << char('a' + j) << '\n';
                    break;
                }
            }
            return;
        }
        res += char('a' + i);
        cnt[i] -= k;
        break;
    }

    int ct = 0;
    for (int i = 0; i < 26; i++) {
        ct += cnt[i] == 0 ? 0 : 1;
    }

    if (ct == 1) {
        // 剩下字符串全相同
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                res += string(cnt[i] / k, 'a' + i);
                if (cnt[i] % k != 0) res += char('a' + i);
                cout << res << '\n';
                return;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        res += string(cnt[i], 'a' + i);
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
