// 1360E 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
            
    auto get = [&](int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n)
            return 1;
        return a[x][y] - '0';
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (get(i, j) == 1 && get(i + 1, j) == 0 && get(i, j + 1) == 0) {
                cout << "NO" << endl;
                return;
            }
    cout << "YES" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
