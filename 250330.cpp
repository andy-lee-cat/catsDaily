// 1368B 1500
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

void printRes(int res) {
    // cout << res << '\n';
    int smcnt = res / 10;
    int sm = 10 - (res % 10);
    string s = "codeforces";
    for (int i = 0; i < sm; i++)
        cout << string(smcnt, s[i]);
    for (int i = sm; i < 10; i++)
        cout << string(smcnt + 1, s[i]);
    cout << '\n';
}

void solve() {
    long long k;
    cin >> k;
    long long l = 9, r = 900;
    while (l < r) {
        long long m = l + (r - l) / 2;
        long long smcnt = m / 10;
        long long sm = 10 - (m % 10);
        long long res = 1;
        for (int i = 0; i < sm; i++)
            res *= smcnt;
        for (int i = sm; i < 10; i++)
            res *= (smcnt + 1);
        if (res < k)
            l = m + 1;
        else
            r = m;
    }
    printRes(l);
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
