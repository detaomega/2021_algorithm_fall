#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

vector<int> G[maxn];
int vis[maxn], occ[maxn], tmp[maxn];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        occ[i] = 0;
        vis[i] = -1;
        tmp[i] = -1;
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    init(n);
    queue<int> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int X;
    cin >> X;
    for (int i = 0; i < X; i++) {
        int k;
        cin >> k;
        q.push(k);
        vis[k] = 0;
    }
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int nxt : G[now]) {
            if (vis[nxt] == -1) {
                vis[nxt] = vis[now] + 1;
                q.push(nxt);
            }
        }
    }
    cin >> X;
    bool ans = 0;
    for (int i = 0; i < X; i++) {
        int k;
        cin >> k;
        occ[k] = true;
    }
    tmp[s] = 0;
    q.push(s);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int nxt : G[now]) {
             if (tmp[nxt] == -1) {
                tmp[nxt] = tmp[now] + 1;
                q.push(nxt);
            }                 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (occ[i] && tmp[i] < vis[i]) {
            ans = true;
        }
    }
    cout << (ans == true ? "Yes\n" : "No\n");
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

