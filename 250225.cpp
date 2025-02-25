// 445A 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                if ((i + j) % 2 == 0) 
                    cout << 'B';
                else
                    cout << 'W';
            } else {
                cout << '-';
            }
        }
        cout << '\n';
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
