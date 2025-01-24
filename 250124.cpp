// 762A 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> divs;
    for (int i = 1; 1ll * i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    if (k > divs.size()) {
        cout << -1 << endl;
    } else {
        cout << divs[k - 1] << endl;
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
