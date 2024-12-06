// 476b 1300
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

long long C(long long k, long long n) {
    long long res = 1;
    for (long long i = 1; i <= k; i++) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int diff = 0;
    int ran = 0;
    for (char c : s1) {
        if (c == '+') {
            diff++;
        } else if (c == '-') {
            diff--;
        }
    }
    for (char c : s2) {
        if (c == '+') {
            diff--;
        } else if (c == '-') {
            diff++;
        } else {
            ran++;
        }
    }
    diff = abs(diff);
    if (ran < diff) {
        cout << 0 << '\n';
        return;
    }
    long long add = (diff + ran) / 2;
    int all = 1 << ran;
    int pos = C(add, ran); 
    cout << fixed << setprecision(9) << (double)pos / all << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
