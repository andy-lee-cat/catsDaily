// 1409D 1500
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long long> pow10;

void init() {
    pow10.push_back(1);
    for (int i = 1; i < 19; i++)
        pow10.push_back(pow10[i - 1] * 10);
}

bool legal(long long n, int s) {
    long long sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum <= s;
}

void solve() {
    long long n;
    int s;
    cin >> n >> s;

    long long res = 0;
    int idx = 0;
    while (!legal(n, s)) {
        if (n % 10 == 0) {
            n /= 10;
            idx++;
        } else {
            int add = 10 - (n % 10);
            res += pow10[idx] * add;
            n += add;
            n /= 10;
            idx++;
        }
    }
    cout << res << '\n';
}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
