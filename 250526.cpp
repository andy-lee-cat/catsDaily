// 1364C 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n, MAX);
    vector<bool> vis(2 * n + 5);
    if (a[0] == 1) { b[0] = 0, vis[0] = true, vis[a[0]] = true; }
    else { vis[0] = false, vis[a[0]] = true; }
    
    for (int i = 0; i < n - 1; i++) {
        vis[a[i + 1]] = true;
        if (a[i] != a[i + 1]) {
            b[i + 1] = a[i];
        }
    }

    vector<int> notuse;
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            notuse.push_back(i);
        }
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == MAX) {
            b[i] = notuse[idx++];
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n - 1];
    
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
