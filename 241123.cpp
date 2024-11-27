// 235A 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<tuple<long long, int, int, int>> q;
    q.push({1ll * n * n * n, n, n, n});
    auto mysort = [](int &a, int &b, int &c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end(), greater<int>());
        a = v[0], b = v[1], c = v[2];
    }; 
    while (!q.empty()) {
        auto [cur, a, b, c] = q.top(); q.pop();
        auto [x, y, z] = make_tuple(a, b, c);
        if (__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) == 1) {
            cout << cur << '\n';
            return;
        }
        a = x - 1, b = y, c = z;
        mysort(a, b, c);
        q.push({1ll * a * b * c, a, b, c});
        
        a = x, b = y - 1, c = z;
        mysort(a, b, c);
        q.push({1ll * a * b * c, a, b, c});

        if (z > 1) {
            a = x, b = y, c = z - 1;
            q.push({1ll * a * b * c, a, b, c});
        }
    }
    return;
    
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
