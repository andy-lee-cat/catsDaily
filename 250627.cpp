// 1538D 1700
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> primes;

void init() {
    primes.push_back(2);
    for (int i = 3; i <= 100000; i += 2) {
        bool isPrime = true;
        for (int p : primes) {
            if (p * p > i) break;
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
}

int getcnt(int val) {
    int cnt = 0;
    for (int p : primes) {
        if (p * p > val) break;
        while (val % p == 0) {
            val /= p;
            cnt++;
        }
    }
    if (val > 1) cnt++;
    return cnt;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int cnta = getcnt(a);
    int cntb = getcnt(b);
    if (k == 1) {
        if (a == b) {
            cout << "NO\n";
            return;
        } else {
            if (a % b == 0 || b % a == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    } else {
        if (cnta + cntb < k) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    int t = 1;
    init();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
