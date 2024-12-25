// 1365C 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> place(n + 1);
    for (int i = 0; i < n; i++)
        place[b[i]] = i;
    vector<int> diff(n + 1);
    for (int i = 0; i < n; i++) 
        diff[a[i]] = (i - place[a[i]] + n) % n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cnt[diff[i]]++;
    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
