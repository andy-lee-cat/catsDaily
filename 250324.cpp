// 1857C 1200
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
        int n;
        cin >> n;
        int m;
        m = (n * (n - 1)) / 2;
        vector<int> nums(m);
        for (int i = 0; i < m; i++)
            cin >> nums[i];
        
        vector<int> res(n);
        sort(nums.begin(), nums.end());
        vector<vector<int>> cnts;
        for (auto num : nums) {
            if (!cnts.size() || cnts.back()[0] != num)
                cnts.push_back({num, 0});
            cnts.back()[1] += 1;
        }
            
        
        auto it = 0;
        for (int i = n - 1; i > 0; i--) {
            int num, cnt;
            num = cnts[it][0], cnt = cnts[it][1];
            if (cnt == 0) {
                it++;
                num = cnts[it][0], cnt = cnts[it][1];
            }
            cnts[it][1] -= i;
            res[i] = cnts[it][0];
        }
        res[0] = nums.back();
        for (int i = 0; i < n; i++)
            cout << res[i] << " \n"[i==n-1];
}


int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
