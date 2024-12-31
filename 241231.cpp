// 510c 1600
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int max_len = 0;
    vector<string> words(n);
    vector<vector<bool>> next(26, vector<bool>(26));
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        max_len = max(max_len, (int)words[i].length());
    }
    for (int i = 0; i < n - 1; i++) {
        string& a = words[i];
        string& b = words[i + 1];
        int lena = a.length();
        int lenb = b.length();
        bool flag = false;
        for (int j = 0; j < min(lena, lenb); j++) {
            if (a[j] == b[j]) continue;
            next[a[j] - 'a'][b[j] - 'a'] = true;
            flag = true;
            break;
        }
        if (!flag && lena > lenb) {
            cout << "Impossible\n";
            return;
        }
    }
    vector<bool> vis(26);
    vector<int> order;
    vector<int> in(26);
    for (int i = 0; i < 26; i++) 
        for (int j = 0; j < 26; j++) 
            if (next[i][j]) 
                in[j]++;

    queue<int> q;
    for (int i = 0; i < 26; i++) 
        if (in[i] == 0) 
            q.push(i);    
    
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (vis[now]) continue;
        order.push_back(now);
        vis[now] = true;
        for (int i = 0; i < 26; i++) {
            if (next[now][i]) {
                in[i]--;
                if (in[i] == 0)
                    q.push(i);
            }
        }
    }
    
    if (order.size() < 26) {
        cout << "Impossible\n";
        return;
    } else {
        for (int i = 0; i < 26; i++)
            cout << (char)(order[i] + 'a');
        cout << '\n';
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
