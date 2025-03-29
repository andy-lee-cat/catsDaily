// 1201B 1500
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long max = *max_element(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL); 
    if (sum % 2 == 1 || max * 2 > sum) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
