// 701C 1500
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<char> exist(s.begin(), s.end());
    unordered_map<char, int> cnts;
    int l = 0;
    int res = n;
    auto isValid = [&]() {
        for (char c : exist) 
            if (cnts[c] == 0)
                return false;
        return true;
    };
    for (int r = 0; r < n; r++) {
        cnts[s[r]]++;
        while (isValid()) {
            res = min(res, r - l + 1);
            cnts[s[l]]--;
            l++;
        }
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
