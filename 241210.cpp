// 1370c 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0) return false;
    return true;
}

void win1() {
    cout << "Ashishgup" << '\n';
}

void win2() {
    cout << "FastestFinger" << '\n';
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) win2();
    else if (n == 2) win1();
    else if (n % 2 == 1) win1();
    else {
        // n is even && n >= 4
        // n = 2^a * b, where b is odd
        int a = 0;
        while (n % 2 == 0) {
            n /= 2;
            a++;
        }
        int b = n;
        if (a == 1) {
            bool isPrime = is_prime(b);
            if (isPrime) win2();
            else win1();
        } else {
            if (b == 1) win2();
            else win1();
        }
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
