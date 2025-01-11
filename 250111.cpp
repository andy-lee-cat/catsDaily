// 276C 1500
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qs[i] = {l, r};
    }
    sort(qs.begin(), qs.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;
    vector<int> cnts(n + 1);
    int idx = 1, qidx = 0;
    for (idx = 1; idx <= n; idx++) {
        while (qidx < q && qs[qidx].first <= idx) {
            pq.push(qs[qidx].second);
            qidx++;
            size++;
        }
        while (!pq.empty() && pq.top() < idx) {
            pq.pop();
            size--;
        }
        cnts[idx] = size;
    }
    sort(cnts.begin(), cnts.end(), greater<int>());
    sort(a.begin(), a.end(), greater<int>());
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += 1LL * a[i] * cnts[i];
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
