// 1692F 1300
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= 10;
        cnt[x]++;
    }
    vector<int> nums;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] > 3) cnt[i] = 3;
        while (cnt[i]--) 
            nums.push_back(i);
    }
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if ((nums[i] + nums[j] + nums[k]) % 10 == 3) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
