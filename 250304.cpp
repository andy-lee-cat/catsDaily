// 584D 1800
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector<int> ps;

void init() {
    ps.resize(0);
    ps.push_back(2);
    for (int i = 3; i < 1e6; i++) {
        for (int p : ps) {
            if (p * p > i) {
                ps.push_back(i);
                break;
            }
            if (i % p == 0) 
                break;
        }
    }
}

bool is_prime(int val) {
    for (int p : ps) {
        if (p * p > val) return true;
        if (val % p == 0) return false;
    }
    return true;
}

void solve() {
    // 1/ln(n)概率找到一个大质数
    int n;
    cin >> n;
    int k = 0;
    int p1;
    int left;
    for (int i = n; i >= 1; i -= 2) {
        if (is_prime(i)) {
            p1 = i;
            left = n - i;
            break;
        }
    }
    if (left == 0) {
        cout << 1 << '\n';
        cout << p1 << '\n';
        return;
    }

    for (int p2 : ps) {
        int p3 = left - p2;
        if (p3 == 0) {
            cout << 2 << '\n';
            cout << p1 << ' ' << p2 << '\n';
            return;
        }
        if (is_prime(p3)) {
            cout << 3 << '\n';
            cout << p1 << ' ' << p2 << ' ' << left - p2 << '\n';
            return;
        }
    }

    // 还没找到，那就是left这个偶数=两个质数相加, 并且俩质数都大于ps的范围
    // 应该不会发生，前面以ln(n)的范围内应该就能找到，那left应该数量级也在ln(n)
    // 还有更强结论，1e9内的质数，距离最大是282
    cout << "error\n";
}

int main() {
    int t = 1;
    init();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
