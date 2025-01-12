// 1475c 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> as(k), bs(k);
    vector<int> cnta(a + 1), cntb(b + 1);
    for (int i = 0; i < k; i++) 
        cin >> as[i];   
    for (int i = 0; i < k; i++)
        cin >> bs[i];
    for (int i = 0; i < k; i++) {
        cnta[as[i]]++;
        cntb[bs[i]]++;
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += k - cnta[as[i]] - cntb[bs[i]] + 1;
    }
    cout << res / 2 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
