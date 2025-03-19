// 1475E 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007

vector<vector<long long>> C(1001, vector<long long>(1001, 0));

void init() {
    // C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
    C[0][0] = 1;
    for (int i = 1; i < 1001; i++) {
        C[i][0] = 1;
        for (int j = 1; j < 1001; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int topk = a[n - k];
    int cnt = 0;
    int large = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == topk)
            cnt++;
        else if (a[i] > topk)
            large++;
    k -= large;
    k = min(k, cnt - k);
    cout << C[cnt][k] << '\n';
}

int main() {
    int t = 1;
    init();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
