// 1497C2 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    while (k > 3) {
        cout << 1 << " ";
        n--;
        k--;
    }
    if (n % 2 == 1) {
        cout << 1 << " " <<
            n / 2 << " " << 
            n / 2 << '\n';
    } else {
        if (n % 4 == 0) {
            cout << n / 2 << " " <<
                n / 4 << " " <<
                n / 4 << '\n';
        } else {
            cout << 2 << " " <<
                (n - 2) / 2 << " " <<
                (n - 2) / 2 << '\n';
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
