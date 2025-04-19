// 1295D 1800
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

// [0, m-1]范围内有多少数和m互质
// 其实就是求m的欧拉函数φ(n)
// 容斥定理求下来和我的结果是一样的
// n * (1-1/p1) * (1-1/p2) * ... * (1-1/pk)
// 等价于每个因子pi, n -= n/pi
long long phi(long long n) {
    long long res = n;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            res -= res / p;
        }
    }
    if (n > 1) 
        res -= res / n;
    return res;
}

// 我自己独立创造出一个算欧拉函数的算法也是挺弔的
void solve() {
    long long a, m;
    cin >> a >> m;
    long long g = gcd(a, m);
    long long oldm = m;
    m /= g;

    if (true) {
        cout << phi(m) << '\n';
        return;
    }

    // 问题转化成[0, m-1]范围内有多少数和m互质
    vector<long long> factors;
    for (long long i = 2; i * i <= m; i++) {
        if (m % i != 0) continue;
        factors.push_back(i);
        while (m % i == 0) 
            m /= i;
    }

    // m是个质数
    if (m > 1) factors.push_back(m);

    m = oldm / g;
    long long notans = 0;
    int n = factors.size();
    for (int i = 1; i < (1 << n); i++) {
        long long mul = 1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                mul *= factors[j];
                cnt++;
            }
        }
        if (cnt % 2 == 1) notans += m / mul;
        else notans -= m / mul;
    }
    cout << m - notans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
