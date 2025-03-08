// 1526C2 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    long long h = 0;
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            h += a[i];
            res++;
        } else {
            if (h + a[i] >= 0) {
                h += a[i];
                res++;
                pq.push(a[i]);
            } else {
                if (!pq.empty() && pq.top() < a[i]) {
                    h -= pq.top(); pq.pop();
                    h += a[i];
                    pq.push(a[i]);
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
