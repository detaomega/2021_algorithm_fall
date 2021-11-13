#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

map<int,int> mp;
pair<int,int
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x] = i - 1;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end()) cout << -1 << "\n";
        else cout << mp[x] << "\n";
    }



}

