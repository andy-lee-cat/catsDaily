// 339d 1700
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(1 << (n + 1));
    for (int i = 0; i < (1 << n); i++) 
        cin >> a[(1 << n) + i];
    // init
    queue<int> q;
    for (int i = (1 << n); i < (1 << (n + 1)); i++) 
        q.push(i);
    for (int i = 0; i < n; i++) {
        int size = q.size();
        for (int j = 0; j < size; j += 2) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            int z = x >> 1;
            if (i % 2 == 0) 
                a[z] = a[x] | a[y];
            else
                a[z] = a[x] ^ a[y];
            q.push(z);
        }
    }

    // query
    for (int _ = 0; _ < m; _++) {
        int p, b;
        cin >> p >> b;
        a[(1 << n) + p - 1] = b;
        int x = (1 << n) + p - 1;
        bool op = true;
        while (x > 1) {
            x = x >> 1;
            if (op)
                a[x] = a[x << 1] | a[(x << 1) + 1];
            else
                a[x] = a[x << 1] ^ a[(x << 1) + 1];
            op = !op;
        }
        cout << a[1] << '\n';
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
