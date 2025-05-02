// 538B 1400
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int N = n;
    vector<int> a;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }
    int num = *max_element(a.begin(), a.end());
    cout << num << '\n';
    vector<string> res(num);
    for (int i = a.size() - 1; i >= 0; i--) {
        int x = a[i];
        for (int i = 0; i < num; i++) {
            if (i < x) {
                res[i] += '1';
            } else if (res[i].size() > 0) {
                res[i] += '0';
            }
        }
    }
    for (int i = 0; i < num; i++) {
        cout << res[i] << " \n"[i == num - 1];
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
