// 1381A2 1700
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> opt;
    bool rev = false;
    int l = 0, r = n - 1;
    int idx = n - 1;
    while (l <= r) {
        if (!rev) {
            if (a[r] == b[idx]) {
                r--;
            } else if (a[l] != b[idx]) {
                opt.push_back(r - l + 1);
                rev = !rev;
                l++;
            } else {
                opt.push_back(1);
                opt.push_back(r - l + 1);
                rev = !rev;
                l++;
            }
        } else {
            if (a[l] != b[idx]) {
                l++;
            } else if (a[r] == b[idx]) {
                opt.push_back(r - l + 1);
                rev = !rev;
                r--;
            } else {
                opt.push_back(1);
                opt.push_back(r - l + 1);
                rev = !rev;
                r--;
            }
        }
        idx--;
    }
    int size = opt.size();
    cout << size << ' ';
    for (int i = 0; i < size; i++) 
        cout << opt[i] << ' ';
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
