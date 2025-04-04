// 1395C 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int res = 0;
    for (int chk = 8; chk >= 0; chk--) {
        bool allfound = true;
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < m; j++) {
                if ((((a[i] & b[j]) >> chk) & 1) == 1) 
                    continue;

                // 找到一个bj可以使得第chk位为0
                found = true;
                
                for (int t = 8; t > chk; t--) {
                    if (
                        ((res >> t) & 1) == 0 &&
                        (((a[i] & b[j]) >> t) & 1) == 1
                    ) {
                        // 这个bj不满足前面位的要求
                        found = false;
                        break;
                    }
                }
                if (found) 
                    break;
            }
            if (!found) {
                allfound = false;
                break;
            }
        }
        if (!allfound) {
            res |= (1 << chk);
        }
    }
    cout << res << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
