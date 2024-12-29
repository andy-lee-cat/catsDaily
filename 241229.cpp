// 5C 1900
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

void merge(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    while (i < n && arr[i] == 0) 
        i++;
    if (i == n) return;
    arr[j] = arr[i];
    for (i = i + 1; i < n; i++) {
        if (arr[i] == 0) {
            j++;
            arr[j] = 0;
        } else {
            arr[j] += arr[i];
        }
    }
    arr.resize(j + 1);
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> part;
    int stk = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk++;
        } else {
            if (stk > 0) {
                stk--;
                now++;
                if (stk == 0) {
                    part.push_back(now);
                    now = 0;
                }
            } else {
                if (part.size() > 0 && part.back() == 0) {
                    continue;
                } else {
                    part.push_back(0);
                }
            }
        }
    }
    // from right to left
    int len = stk + now * 2;
    now = 0;
    stk = 0;
    vector<int> tmppart;
    for (int i = n - 1; i >= n - len; i--) {
        if (s[i] == ')') {
            stk++;
        } else {
            if (stk > 0) {
                stk--;
                now++;
                if (stk == 0) {
                    tmppart.push_back(now);
                    now = 0;
                }
            } else {
                if (tmppart.size() > 0 && tmppart.back() == 0) {
                    continue;
                } else {
                    tmppart.push_back(0);
                }
            }
        }
    }
    merge(tmppart);
    merge(part);
    for (int i = tmppart.size() - 1; i >= 0; i--) {
        part.push_back(tmppart[i]);
    }
    int max_len = *max_element(part.begin(), part.end());
    int cnt = 0;
    for (auto v : part) 
        if (v == max_len) 
            cnt++;
    if (max_len == 0) 
        cout << 0 << " " << 1 << endl;
    else 
        cout << max_len * 2 << " " << cnt << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
