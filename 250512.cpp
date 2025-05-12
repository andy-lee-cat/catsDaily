// 1399D 1500
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> zero, one;
    vector<int> res;
    for (char c : s) {
        c -= '0';
        if (c == 0) {
            if (one.size()) {
                int idx = one.back(); one.pop_back();
                zero.push_back(idx);
                res.push_back(idx);
            } else {
                int idx = zero.size() + 1;
                zero.push_back(idx);
                res.push_back(idx);
            }
        } else {
            if (zero.size()) {
                int idx = zero.back(); zero.pop_back();
                one.push_back(idx);
                res.push_back(idx);
            } else {
                int idx = one.size() + 1;
                one.push_back(idx);
                res.push_back(idx);
            }
        }
    }
    cout << *max_element(res.begin(), res.end()) << '\n';
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
