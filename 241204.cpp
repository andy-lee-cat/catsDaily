// 514A 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for (char &c : s) {
        if (c >= '5' && c <= '9') {
            c = '9' - (c - '0');
            if (cnt == 0 && c == '0') 
                c = '9';
        }
        cnt++;
    }
    cout << s << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
