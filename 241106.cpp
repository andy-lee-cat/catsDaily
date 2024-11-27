// 1352G 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "-1\n";
        return;
    }
    vector<int> res(n + 4);
    int num = 1;
    for (int i = 0; i < n; i += 4) {
        res[i] = i + 2;
        res[i + 1] = i + 4;
        res[i + 2] = i + 1;
        res[i + 3] = i + 3;
    }
    if (n % 4 == 0) {
        // do nothing
    } else if (n % 4 == 1) {
        res[n - 1] = n;
    } else if (n % 4 == 2) {
        res[n - 1] = n;
        res[n - 2] = res[n - 3];
        res[n - 3] = n - 1;
    } else if (n % 4 == 3) {
        res[n - 1] = n - 1;
        res[n - 2] = n - 4;
        res[n - 3] = n;
        res[n - 4] = n - 3;
        res[n - 5] = n - 6;
        res[n - 6] = n - 2;
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
