// 1538F 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int cnts[10];

void init() {
    for (int i = 0; i < 10; i++)
        cnts[i] = 0;
    
    // cnts[0] -> add 1
    // cnts[1] -> add 10
    cnts[0] = 1;
    for (int i = 1; i < 10; i++) {
        cnts[i] = cnts[i - 1] * 10 + 1;
    }
}

int getRes(int n) {
    int res = 0;
    for (int i = 0; n && i < 10; i++) {
        int num = n % 10;
        n /= 10;
        res += cnts[i] * num;
    }
    return res;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int lres = getRes(l), rres = getRes(r);
    cout << rres - lres << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
