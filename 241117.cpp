// 479C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());
    int now = 0;
    for (auto [a, b] : ab) {
        if (now <= b) now = b;
        else now = a;
    }
    cout << now << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
