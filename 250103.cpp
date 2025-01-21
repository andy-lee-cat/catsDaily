// 1353D 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1;
    int loop = 0;
    int alice = 0, bob = 0;
    int last = 0;
    while (l <= r) {
        int now = 0;
        if (loop % 2 == 0) {
            do {
                now += a[l++];
            } while (l <= r && now <= last);
            alice += now;
        } else {
            do {
                now += a[r--];
            } while (l <= r && now <= last);
            bob += now;
        }
        last = now;
        loop++;
    }
    cout << loop << " " << alice << " " << bob << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
