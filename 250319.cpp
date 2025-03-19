// 1475E 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007

long long power(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

vector<long long> fact(1001, 1);
vector<long long> invfact(1001, 1);

vector<vector<long long>> C(1001, vector<long long>(1001, 0));

void init2() {
    for (int i = 2; i < 1001; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = power(fact[i], MOD - 2);
    }
}

long long get_C(long long n, long long k) {
    if (n < k) return 0;
    return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD;
}

void init() {
    // C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
    C[0][0] = 1;
    for (int i = 1; i < 1001; i++) {
        C[i][0] = 1;
        for (int j = 1; j < 1001; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int topk = a[n - k];
    int cnt = 0;
    int large = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == topk)
            cnt++;
        else if (a[i] > topk)
            large++;
    k -= large;
    k = min(k, cnt - k);
    // cout << C[cnt][k] << '\n';
    cout << get_C(cnt, k) << '\n';
}

int main() {
    int t = 1;
    // init();
    init2();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
