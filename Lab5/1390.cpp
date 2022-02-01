#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
vector<int> G[maxn], rG[maxn], nG[maxn];
int vis[maxn], scc[maxn], cnt = 1, val[maxn], in[maxn], dp[maxn];
vector<int> order;

void dfs_1(int now) {
    vis[now] = true;
    for (int k : G[now]) {
        if (vis[k] == false) {
            dfs_1(k);
        } 
    }
    order.push_back(now);
}

void dfs_2(int now) {
    
    scc[now] = cnt;
    val[cnt]++;
    for (int k : rG[now]) {
        if (scc[k] == false) {
            dfs_2(k);
        }
    }
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) 
            dfs_1(i);    
    }
    reverse(order.begin(), order.end());
    for (int k : order) {
        if (!scc[k]) {
         
            dfs_2(k);
            cnt = cnt + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int k : G[i]) {
            if (scc[i] != scc[k]) {
                nG[scc[i]].push_back(scc[k]);
                in[scc[k]]++;
            }
        }
    }
    
    queue<int> q;
    for (int i = 1; i < cnt; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = val[i];
        }
    }
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int k : nG[now]) {
            dp[k] = max(dp[k], dp[now] + val[k]);
            in[k]--;
            if (in[k] == 0) {
                q.push(k);
            }
        }
    }
    cout << *max_element(dp + 1, dp + cnt) << "\n";
}

