// 1B 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    while (l < n && !isdigit(s[l]))
        l++;
    while (l < n && isdigit(s[l]))
        l++;
    if (l == n) {
        // BC23
        l = 0;
        int r = 0, c = 0;
        while (l < n && isalpha(s[l])) {
            c *= 26;
            c += (s[l] - 'A' + 1);
            l++;
        }
        while (l < n) {
            r = r * 10 + (s[l] - '0');
            l++;
        }
        cout << 'R' << r << 'C' << c << '\n';
    } else {
        //R23C55
        int r = stoi(s.substr(1, l - 1));
        int c = stoi(s.substr(l + 1));
        c--;
        string ans;
        while (c >= 0) {
            ans += (c % 26) + 'A';
            c /= 26;
            c--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << r << '\n';
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
