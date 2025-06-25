// 1486D 2100
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 判断{-1,1}数组a是否存在长度至少为k的子数组，其和大于0
bool judge(const vector<int>& a, int k) {
    int n = a.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];
    
    // 以i为结尾的子数组的最大和
    vector<int> maxend(n, 0);
    maxend[0] = a[0];
    for (int i = 1; i < n; i++) 
        maxend[i] = a[i] + max(0, maxend[i - 1]);
    
    // 右端点是i，区间长度为k-1的子数组，加上以i-k+1为结尾的最大和
    for (int i = k - 1; i < n; i++) 
        if (prefix[i + 1] - prefix[i + 1 - (k - 1)] + maxend[i - (k - 1)] > 0)
            return true;
    
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        vector<int> b(n);
        for (int i = 0; i < n; i++) 
            b[i] = a[i] >= m ? 1 : -1;
        
        if (judge(b, k)) l = m + 1;
        else r = m;
    }
    cout << l - 1 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
