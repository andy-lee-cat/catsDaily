// 546C 1400
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
using namespace std;

int N = 10;

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    deque<int> a, b;
    while (m--) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    int round = 0;
    while (a.size() && b.size()) {
        int x = a.front(); a.pop_front();
        int y = b.front(); b.pop_front();
        if (x < y) {
            b.push_back(x);
            b.push_back(y);
        } else {
            a.push_back(y);
            a.push_back(x);
        }
        round++;
        if (round > 1e6) {
            cout << "-1\n";
            return;
        }
    }
    if (a.size()) {
        cout << round << " " << 1 << "\n";
    } else {
        cout << round << " " << 2 << "\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
