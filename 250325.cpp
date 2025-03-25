// 1352E 1500
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
    vector<bool> exist(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int sum = a[i];
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            if (sum <= n)
                exist[sum] = true;
            else
                break;
        }
    }    
    int res = 0;
    for (int i = 0; i < n; i++)
        if (exist[a[i]])
            res++;
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
