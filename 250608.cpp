// 1605C 1400
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
void solve() {
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    int res = 0;
    // check "aa"
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'a') {
            cout << "2\n";
            return;
        }
    }

    // check "a?a"
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'a' && s[i + 2] == 'a') {
            cout << "3\n";
            return;
        }
    }
    
    for (int i = 4; i <= 7; i++) {
        for (int j = 0; j <= n - i; j++) {
            vector<int> cnt(3);
            for (int k = 0; k < i; k++) {
                cnt[s[j + k] - 'a']++;
            }
            if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                cout << i << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
