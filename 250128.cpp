// 1919C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = INT_MAX, t = INT_MAX;
    int res = 0;
    // s t v
    // s v t
    // v s t
    for (auto v : a) {
        if (v > t) {
            res++;
            s = v;
            swap(s, t);
        } else if (v > s) {
            t = v;
        } else {
            s = v;
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
