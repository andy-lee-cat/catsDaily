// 1920C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    vector<int> temp;
    int len, loop;
    int gcd;
    auto calc = [&]() {
        gcd = 0;
        for (int j = 0; j < loop - 1; j++) {
            for (int k = 0; k < len; k++) {
                gcd = __gcd(gcd, abs(a[j * len + k] - a[(j + 1) * len + k]));
                if (gcd == 1) break;
            }
            if (gcd == 1) break;
        }
        res += gcd != 1 ? 1 : 0;      
    };

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        len = i, loop = n / i;
        calc();
        if (len != loop) {
            swap(len, loop);
            calc();
        }
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
