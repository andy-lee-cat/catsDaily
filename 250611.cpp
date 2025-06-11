// 1437D 1600
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[0] = n + 1;
    int depth = 0;
    int diff = 0;
    int lastnode = 0, nownode = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            diff++;
            if (diff >= lastnode) {
                depth++;
                lastnode = nownode;
                diff = 0;
                nownode = 1;
            } else {
                nownode++;
            }
        } else {
            nownode++;
        }
    }
    cout << depth << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
