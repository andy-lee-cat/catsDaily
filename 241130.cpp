// 1348B 1400
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_set<int> set;
    // 最好用set而不是unordered_set
    // gpt说两次相邻遍历结果也不一定相同
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        set.insert(a[i]);
    }
    if (set.size() > k) {
        cout << "-1\n";
        return;
    }
    cout << n * k << '\n';
    for (int i = 0; i < n; i++) {
        for (int val : set) {
            cout << val << ' ';
        }
        // for (int val : unordered_set) 
            // cout << val << ' ';
        // for (int val : unordered_set) 
            // cout << val << ' ';
        
        
        for (int j = 0; j < k - set.size(); j++) {
            cout << *set.begin() << ' ';
        }
    } 
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
