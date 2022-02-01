#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
vector<pair<int,int>> G[maxn];
int p[maxn], sz[maxn], ans = 0, n, m;


struct Edge {
    int u, v, w;
};

vector<Edge> edge;

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

bool merge(int u, int v) {
    u = f(u);
    v = f(v);
    if (u == v) return false;
    p[u] = v;
    return true;
}

void dfs(int now,int fa) {
    sz[now] = 1;
    for (auto [k, w] : G[now]) {
        if (k != fa) {
            dfs (k, now);
            ans = ans + (((n - sz[k]) * sz[k]) % mod) * w;
            ans = ans % mod;
            sz[now] += sz[k];
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort (edge.begin(), edge.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    int tot = 0, span = 0;
    for (auto [u, v, w] : edge) {
        if (merge(u, v)) {
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
            tot++;
            span += w;
        }
    }
    if  (tot != n - 1) {
        cout << "-1";
        return 0;
    }
    else {
        dfs (1, 0);
        cout << (span * 2) % mod << " " << (ans * 2) % mod << "\n";
    }
}
