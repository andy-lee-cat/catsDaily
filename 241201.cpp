// 1294c 1300
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector<int> prime;
void init() {
    prime.clear();
    prime.push_back(2);
    for (int i = 3; i < 1e5; i++) {
        bool is_prime = true;
        for (int v : prime) {
            if (v * v > i) break;
            if (i % v == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) prime.push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    for (int v : prime) {
        if (v * v > n) break;
        while (n % v == 0) {
            a.push_back(v);
            n /= v;
        }
    }
    if (n > 1) a.push_back(n);
    if (a.size() < 3) {
        cout << "NO\n";
        return;
    }
    set<int> res;
    res.insert(a[0]);
    int now = 1;
    for (int i = 1; i < a.size(); i++) {
        now *= a[i];
        if (res.find(now) != res.end()) continue;
        res.insert(now);
        now = 1;
    }
    if (res.size() < 3) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        int cnt = 0;
        int x = now;
        for (int v : res) {
            if (cnt < 2) {
                cout << v << " ";
                cnt++;
            } else {
                x *= v;
            }
        }
        cout << x << '\n';
    }
}

int main() {
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}
