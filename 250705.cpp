// 1779C 1600
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    m--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0; 
    long long left = 0;
    if (m != 0 && a[m] > 0) {
        res++;
        a[m] = -a[m];
    }

    left = a[m];
    priority_queue<int> pq;
    // i > 0不是 i>=0, i>=0 把空集也算进去了
    for (int i = m - 1; i > 0; i--) {
        left += a[i];
        pq.push(a[i]);
        while (left > 0) {
            int val = pq.top(); pq.pop();
            left -= 2 * val;
            res++;
        }
    }
    
    priority_queue<int, vector<int>, greater<int>> pq2;
    left = 0;
    for (int i = m + 1; i < n; i++) {
        left += a[i];
        pq2.push(a[i]);
        while (left < 0) {
            int val = pq2.top(); pq2.pop();
            left -= 2 * val;
            res++;
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
