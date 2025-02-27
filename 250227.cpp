// 1541B 1200
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
    vector<int> mmap(2 * n + 1, 0);
    for (int i = 0; i < n; i++)
        mmap[a[i]] = i + 1;
    int res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = i + 1; j <= 2 * n && 1ll * i * j < 2 * n; j++) {
            if (mmap[i] && mmap[j] && mmap[i] + mmap[j] == i * j) {
                res++;
            }
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
