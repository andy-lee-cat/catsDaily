// 75C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a, b;
int gcd;
vector<int> ls;

void init() {
    cin >> a >> b;
    gcd = __gcd(a, b);
    for (int i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            ls.push_back(i);
            if (i * i != gcd)
                ls.push_back(gcd / i);
        }
    }
    sort(ls.begin(), ls.end(), greater<int>());
}

void solve() {
    int low, high;
    cin >> low >> high;
    for (int l : ls) {
        if (l >= low && l <= high) {
            cout << l << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
