// 1335d 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    string s;
    vector<vector<int>> a(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            int num = s[j] - '1';
            a[i][j] = num;
        }
    }
    auto motify = [&](int i, int j) {
        a[i][j] = (a[i][j] + 1) % 9;
    };
    motify(0, 0);
    motify(1, 3);
    motify(2, 6);
    motify(3, 1);
    motify(4, 4);
    motify(5, 7);
    motify(6, 2);
    motify(7, 5);
    motify(8, 8);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cout << a[i][j] + 1 << (j == 8 ? "\n" : "");
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
