// 1520E 1400
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int star_cnt = count_if(s.begin(), s.end(), [](char c) {
        return c == '*';
    });
    int mid;
    int left;
    if (star_cnt % 2 == 1) {
        int need = (star_cnt + 1) / 2;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                need--;
                if (need == 0) {
                    mid = i;
                    break;
                }
            }
        }
        left = mid - star_cnt / 2;
    } else {
        int need = star_cnt / 2;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                need--;
                if (need == 0) {
                    mid = i;
                    break;
                }
            }
        }
        left = mid - star_cnt / 2 + 1;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            res += abs(i - left);
            left++;
        }
    }
    cout << res << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
