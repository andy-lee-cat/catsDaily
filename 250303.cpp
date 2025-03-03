// 1367C 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ones;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            ones.push_back(i);
    int res = 0;
    if (ones.size() == 0) {
        res = 1;
        res += (n - 1) / (k + 1);
        cout << res << '\n';
        return;
    }

    int idx = 0;
    int now = 0;
    while (now < n) {
        if (idx < ones.size() && now >= ones[idx] - k) {
            now = ones[idx] + k + 1;
            idx++;
        } else {
            res++;
            now += k + 1;
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
