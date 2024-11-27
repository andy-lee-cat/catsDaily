// 220B 1800
// 有一系列数，每个数有频次
// 只用处理频次大于等于这个数的数
// 那要处理的数不会超过O(sqrt(n))
// proof: 
// 如果一个数x出现频次Count(x) > sqrt(n), 那么这种数受总频数为n的限制，这种数的种类不会超过sqrt(n)
// 如果一个数出现频次Count(x) < sqrt(n), 且存在 x < Count(x) < sqrt(x), 所以x∈[1, sqrt(n))，种类也不会超过sqrt(n)

// 方法2用的mo算法，时间复杂度O(n * sqrt(n))
// 用一个block大小为sqrt(n)的块，对查询{l, r} 依据 {l/block, r}排序
// 然后转移结果
// mo算法还是很简单而且很实用的

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<tuple>
#include<cmath>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= n)
            cnt[a[i]]++;
    }
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    vector<int> prefix(n + 1);
    vector<int> res(m);
    for (auto [num, c] : cnt) {
        if (num > c) continue;
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + (a[i] == num);
        for (int i = 0; i < m; i++) 
            res[i] += prefix[r[i]] - prefix[l[i] - 1] == num;
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << '\n';
}

void solve_mo() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<tuple<int, int, int>> queries(m);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }
    int block = int(sqrt(n));
    sort(queries.begin(), queries.end(), [&](auto &lhs, auto &rhs) {
        auto [l1, r1, i1] = lhs;
        auto [l2, r2, i2] = rhs;
        l1 /= block;
        l2 /= block;
        return make_tuple(l1, r1) < make_tuple(l2, r2);
    });
    vector<int> res(m);
    int left = 0, right = 0;  // [left, right]
    int ans = 0;
    unordered_map<int, int> cnt;
    if (cnt[a[0]] == a[0]) ans++;
    auto move = [&] (int pos, int sign) -> void {
        if (sign == 1) {
            // add
            if (cnt[a[pos]] == a[pos]) ans--;
            cnt[a[pos]]++;
            if (cnt[a[pos]] == a[pos]) ans++;
        } else {
            // remove
            if (cnt[a[pos]] == a[pos]) ans--;
            cnt[a[pos]]--;
            if (cnt[a[pos]] == a[pos]) ans++;
        }
    };
    for (auto [l, r, id] : queries) {
        while (left > l) move(--left, 1);
        while (right < r) move(++right, 1);
        while (left < l) move(left++, -1);
        while (right > r) move(right--, -1);
        res[id] = ans;
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << '\n';
}

int main() {
    // solve();
    solve_mo();
    return 0;
}
