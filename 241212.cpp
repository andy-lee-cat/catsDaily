// 126b 1700
// 有点怪，为什么tle了
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void get_lps(string& s, vector<int>& lps) {
    int n = s.length();
    lps.resize(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) 
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
}

void solve() {
    string s;
    cin >> s;
    vector<int> lps;
    get_lps(s, lps);
    int n = s.length();
    int maxlen = lps[n - 1];
    if (maxlen == 0) {
        cout << "Just a legend\n";
        return;
    }
    string prefix = s.substr(0, maxlen);
    // 判断中间(不包含suffix)是否有prefix
    // auto test = s.find(prefix, 1);
    // auto test2 = string::npos - maxlen; // 这样写不对
    // if (s.find(prefix, 1) != n - maxlen) {
    //     cout << prefix << '\n';
    // } else {
    //     maxlen = lps[maxlen - 1];
    //     if (maxlen == 0) {
    //         cout << "Just a legend\n";
    //     } else {
    //         cout << s.substr(0, maxlen) << '\n';
    //     }
    // }
    for (int i = 1; i < n - 1; i++) {
        if (lps[i] == maxlen) {
            cout << prefix << '\n';
            return;
        }
    }
    maxlen = lps[maxlen - 1];
    if (maxlen == 0) {
        cout << "Just a legend\n";
    } else {
        cout << s.substr(0, maxlen) << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
