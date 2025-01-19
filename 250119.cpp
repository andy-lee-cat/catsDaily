// 514B 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

void change(int &a, int &b) {
    int gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;
    if (a < 0) {
        a = -a;
        b = -b;
    }
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        xi -= x, yi -= y;
        change(xi, yi);
        d[i] = {xi, yi};
    }
    unordered_set<pair<int, int>, pair_hash> s(d.begin(), d.end());
    cout << s.size() << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
