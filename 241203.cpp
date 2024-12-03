#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

void solve() {
    double r, x, y, x_, y_;
    cin >> r >> x >> y >> x_ >> y_;
    cout << ceil(sqrt(pow(x - x_, 2) + pow(y - y_, 2)) / (2 * r)) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
