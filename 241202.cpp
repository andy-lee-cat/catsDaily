#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime;

void init() {
    prime.clear();
    prime.push_back(2);
    for (int i = 3; i < 1e5; i++) {
        bool is_prime = true;
        for (int v : prime) {
            if (v * v > i) break;
            if (i % v == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) prime.push_back(i);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << "1\n";
        return;
    }
    for (int i = 2; i < sqrt(n) + 2; i++) {
        if (n % i == 0 && n / i <= k) {
            cout << i << '\n';
            return;
        }
    }
    for (int i = sqrt(n) + 2; i >= 2; i--) {
        if (n % i == 0 && i <= k) {
            cout << n / i << '\n';
            return;
        }
    }
    cout << n << '\n';
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
