// 515c 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long f(long long n) {
    long long res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

void test() {
    cout << f(7) * f(2) * f(3) * f(3) << '\n'; 
    cout << f(9) << '\n';
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '4') {
            a.push_back(2);
            a.push_back(2);
            a.push_back(3);
        } else if (s[i] == '6') {
            a.push_back(5);
            a.push_back(3);
        } else if (s[i] == '8') {
            a.push_back(7);
            a.push_back(2);
            a.push_back(2);
            a.push_back(2);
        } else if (s[i] == '9') {
            a.push_back(7);
            a.push_back(3);
            a.push_back(3);
            a.push_back(2);
        } else if (s[i] != '1') {
            a.push_back(s[i] - '0');
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < a.size(); i++)
        if (a[i] > 1) 
            cout << a[i];
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    // test();
    while (t--) {
        solve();
    }
    return 0;
}
