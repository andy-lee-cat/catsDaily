// 1396A 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    // a1 a2 ... an
    // step 1: add ai * (n - 1) to ai i ∈ [1, n - 1]
    // step 2: add an * (n - 1) to an
    // now: ai -> ai * n
    // step 3: dec ai by (n * ai)
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n";
        cout << -a[1] << '\n';
        return;
    } 

    // step 1
    cout << 1 << " " << n - 1 << '\n';
    for (int i = 1; i < n; i++) 
        cout << a[i] * (n - 1) << " \n"[i == n - 1];

    // step 2
    cout << n << " " << n << '\n';
    cout << a[n] * (n - 1) << '\n';

    // step 3
    cout << 1 << " " << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << -a[i] * n << " \n"[i == n];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
