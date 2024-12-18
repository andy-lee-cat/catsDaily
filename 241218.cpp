// 1372B 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> primes;

void init() {
    primes.push_back(2);
    for (int i = 3; i < 1e5; i++) {
        bool is_prime = true;
        for (auto p : primes) {
            if (p * p > i) break;
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            primes.push_back(i);
    }
}

void solve() {
    long long n;
    cin >> n;
    // // n is even
    // if (n % 2 == 0) {
    //     cout << n / 2 << " " << n / 2 << '\n';
    //     return;
    // }
    // n is odd
    for (auto p : primes) {
        if (n % p == 0) {
            cout << n / p << " " << n - n / p << '\n';
            break;
        }
    }
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
