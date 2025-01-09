// 1344A 1600
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int mod(int x, int m) {
    return ((x % m) + m) % m;
}

bool allZerotoN(vector<int>& a) {
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != i)
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        a[i] = mod(a[i] + i, n);
    
    if (allZerotoN(a)) 
        cout << "YES\n";
    else
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
