#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> primes;

void init() {
    primes.push_back(2);
    for (int i = 3; i <= 1000; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(i);
    }
    // long long mul = 1;
    // for (int i = 0; i < 11; i++) 
    //     mul *= primes[i];
    // cout << mul << endl; // 200560490130
}

void solve() {
    int n;
    cin >> n;
    vector<int> color(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 13; j++) {
            if (x % primes[j] == 0) {
                color[i] = j;
                break;
            }
        }
    }
    vector<int> usecolor(13, 0);
    for (int i = 0; i < n; i++) {
        usecolor[color[i]]++;
    } 
    vector<int> f(13, 0);
    int now = 0;
    for (int i = 0; i < 13; i++) {
        if (usecolor[i] > 0) {
            f[i] = now;
            now++;
        } 
    }
    cout << now << '\n';
    for (int i = 0; i < n; i++) {
        cout << f[color[i]] + 1 << " \n"[i == n - 1];
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
