// 735D 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (n == 4) {
        cout << "2\n";
        return;
    }
    if (isPrime(n)) {
        cout << "1\n";
        return;
    }
    if (n % 2 == 1) {
        if (isPrime(n - 2)) {
            cout << "2\n";
            return;
        } else {
            cout << "3\n";
            return;
        }
    } else {
        cout << "2\n";
    }
    
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
