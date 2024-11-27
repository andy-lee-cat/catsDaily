// 371c 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    int nb, ns, nc;
    int pb, ps, pc;
    long long money;
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> money;
    long long l = 0, r = 1e13;
    int need_b = 0, need_s = 0, need_c = 0;
    for (char c : s) {
        if (c == 'B') need_b++;
        if (c == 'S') need_s++;
        if (c == 'C') need_c++;
    }
    while (l < r) {
        long long m = l + (r - l) / 2;
        long long cost = max(0ll, m * need_b - nb) * pb + 
            max(0ll, m * need_s - ns) * ps + 
            max(0ll, m * need_c - nc) * pc;
        if (cost <= money) {
            l = m + 1;
        } else {
            r = m;
        }
    } 
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
