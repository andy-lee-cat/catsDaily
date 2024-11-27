// 1398c 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        a[i] = s[i] - '0' - 1;
    unordered_map<int, int> cnts;
    long long res = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) 
            res++;
        if (cnts.count(-sum - a[i])) {
            res += cnts[-sum - a[i]];
        }
        cnts[-sum]++;
        sum += a[i];
    }
    cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
