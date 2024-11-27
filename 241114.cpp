// 1526B 1400
// 14:05-14:09
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int x;
    cin >> x;
    for (int i =  0; i < 111; i++) {
        int now = x - i * 11;
        if (now < 0) break;
        if (now % 111 == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
