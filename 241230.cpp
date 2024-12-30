// 1506D 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    map<int, int> cnts;
    for (auto v : a)
        cnts[v]++;
    auto it = max_element(cnts.begin(), cnts.end(), [](const pair<int, int> a, const pair<int, int> b) {
        return a.second < b.second;
    });
    int max_cnt = it->second;
    if (max_cnt <= n / 2) {
        cout << n % 2 << '\n';
    } else {
        cout << max_cnt - (n - max_cnt) << '\n';
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
