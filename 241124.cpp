// 1352C 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;;
    cin >> n >> k;
    int loop = (k - 1) / (n - 1);
    int left = (k - 1) % (n - 1);
    cout << n * loop + left + 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
