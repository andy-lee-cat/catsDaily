// 1366D 2000
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 10000000

vector<int> minFactor(N + 1, 0);
vector<pair<int, int>> res;

void init() {
    for (int i = 2; i <= N; i++) {
        if (minFactor[i] != 0) continue;
        for (int j = 1; i * j <= N; j++) {
            if (minFactor[i * j] == 0) {
                minFactor[i * j] = i;
            }
        }
    }
}

void solve() {
    int a;
    cin >> a;
    vector<int> factors;
    while (a > 1) {
        int factor = minFactor[a];
        if (factors.empty() || factors.back() != factor)
            factors.push_back(factor);
        a /= factor;
    }
    if (factors.size() == 1) res.push_back({-1, -1});
    else {
        int x = factors[0];
        int y = 1;
        for (int i = 1; i < factors.size(); i++)
            y *= factors[i];
        res.push_back({x, y});
    }
}

int main() {
    int t = 1;
    init();
    cin >> t;
    res.clear();
    while (t--) {
        solve();
    }
    for (auto &[x, y] : res) {
        cout << x << " ";
    }
    cout << '\n';
    for (auto &[x, y] : res) {
        cout << y << " ";
    }
    cout << '\n';
    return 0;
}
