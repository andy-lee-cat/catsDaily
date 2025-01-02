// 1365B 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    bool sorted = is_sorted(a.begin(), a.end());
    bool all_same = all_of(b.begin(), b.end(), [&](int x) { return x == b[0]; });
    if (sorted || !all_same) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
