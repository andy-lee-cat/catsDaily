// 1350B 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<long long> res(n + 1);
    for (int i = n; i >= 1; i--) {
        res[i] = 1;
        for (int k = 2; k * i <= n; k++)
            if (a[i] < a[k * i])
                res[i] = max(res[i], 1 + res[k * i]);
    }
    cout << *max_element(res.begin(), res.end()) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
