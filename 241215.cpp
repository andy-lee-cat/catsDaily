// 276B 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void first() {
    cout << "First\n";
}

void second() {
    cout << "Second\n";
}

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
        c -= 'a';
        cnt[c]++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
        }
    }
    if (odd <= 1 || odd % 2 == 1) 
        first();
    else
        second();
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
