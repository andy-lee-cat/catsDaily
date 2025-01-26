// 450B 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long MOD = 1e9 + 7;

void solve() {
    long long x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<long long> res = {x, y, y - x, -x, -y, x - y};
    cout << (res[(n - 1) % 6] % MOD + MOD) % MOD << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
