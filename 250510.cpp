// 1519C 1400
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Info {
    vector<int> arr;
    vector<long long> ps;
    long long sum;
public:
    Info() : arr(0), sum(0), ps(0) {}
    int len() {
        return arr.size();
    }
    void add(int v) {
        arr.push_back(v);
    }
    void init() {
        sort(arr.begin(), arr.end());
        ps.resize(arr.size() + 1);
        ps[0] = 0;
        for (int i = 1; i <= arr.size(); i++) {
            ps[i] = ps[i - 1] + arr[i - 1];
        }
        sum = accumulate(arr.begin(), arr.end(), 0ll);
    }
    long long query(int n) {
        int left = arr.size() % n;
        return sum - ps[left];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> u(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> u[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    map<int, Info> mp;
    for (int i = 0; i < n; i++) {
        mp[u[i]].add(s[i]);
    }
    for (auto& [k, v] : mp) {
        v.init();
    }
    vector<long long> res(n + 1);
    for (auto& [k, v] : mp) {
        for (int i = 1; i <= v.len(); i++) {
            res[i] += v.query(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
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
