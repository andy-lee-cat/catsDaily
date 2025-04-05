// 1342C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int a, b, q;
    cin >> a >> b >> q;
    int T = a * b;
    vector<int> pre(T, 0);
    int sum = 0;
    for (int i = 0; i < T; i++) {
        if ((i % a) % b != (i % b) % a) {
            pre[i] = 1;
            sum++;
        }
    }

    auto getRes = [&](long long x) {
        long long loop = x / T;
        int left = x % T;
        long long res = loop * sum;
        for (int i = 0; i <= left; i++) {
            res += pre[i];
        }
        return res;
    };

    while (q--) {
        long long l, r;
        cin >> l >> r;
        long long res = getRes(r) - getRes(l - 1);
        cout << res << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
