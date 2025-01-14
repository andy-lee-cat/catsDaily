// 1514C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> res;
    int mul = 1;
    for (int i = 1; i < n; i++) {
        if (__gcd(i, n) != 1) continue;
        res.push_back(i);
        mul = (1ll * mul * i) % n;
    }
    if (mul == 1) {
        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " \n"[i == res.size() - 1];
        }
    } else {
        cout << res.size() - 1 << '\n';
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == mul) continue;
            cout << res[i] << ' ';
        }
        cout << '\n';
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
