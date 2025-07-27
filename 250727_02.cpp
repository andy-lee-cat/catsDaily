// 577B 1900
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnts(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnts[x % m]++;
    }
    if (cnts[0] > 0 || n >= m) {
        cout << "YES\n";
        return;
    }


    set<int> possibles = {0};
    for (int i = 1; i < m; i++) {
        set<int> newp;
        for (int p : possibles) {
            for (int cnt = 1; cnt <= cnts[i]; cnt++) {
                int newnum = (p + cnt * i) % m;
                if (newnum == 0) {
                    cout << "YES\n";
                    return;
                }
                newp.insert(newnum);
            }
        }
        for (int p : newp) 
            possibles.insert(p);
    }
    cout << "NO\n";
    return;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
