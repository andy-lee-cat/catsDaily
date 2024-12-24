// 1363B 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = n;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1') 
            res++;
    ans = min(ans, res);
    // 000000 -> 1111100000
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') 
            res++;
        else 
            res--;
        ans = min(ans, res);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') 
            res++;
        else 
            res--;
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
