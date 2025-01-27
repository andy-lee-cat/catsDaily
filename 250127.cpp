// 1542B 1500
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    if (b == 1) {
        cout << "YES\n";
        return;
    } 
    long long now = 1;
    while (now <= n) {
        if (now % b == n % b) {
            cout << "YES\n";
            return;
        } else {
            if (a == 1) break;
            now *= a;
        }
    }
    cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
