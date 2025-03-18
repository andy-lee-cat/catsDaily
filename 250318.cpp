// 1542C 1600
// 看答案才会的
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD (int)(1e9 + 7)

long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}


void solve() {
    long long x;
    cin >> x;
    vector<long long> lcms(100);
    lcms[0] = 1;
    for (int i = 1; i <= 42; i++) {
        lcms[i] = lcm(lcms[i - 1], i);
    }

    vector<long long> cnts(42);
    long long res = 0;
    // 遍历所有可能的fi
    for (int fi = 2; fi < 42; fi++) {
        // 结果是f(i) = fi的i的个数是x/lcm[i-1] - x/lcm[i]
        long long cnt_i = x / lcms[fi - 1] - x / lcms[fi];
        res += cnt_i * fi;
        res %= MOD;
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
