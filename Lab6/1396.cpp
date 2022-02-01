#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

vector<pair<int,int>> G[maxn][2];
int dist[maxn][2];

struct Node {
    int id, w;
    bool operator < (const Node &cmp) const {
        return cmp.w < w;
    }
};

struct Edge {
    int u, v, w;
};

vector<Edge> edge;
priority_queue<Node> pq;

void dijk(int now, int type) {
    pq.push({now, 0});
    while (pq.size()) {

        auto [cur, val] = pq.top();
        pq.pop();
        if (dist[cur][type] <= val) continue;
        dist[cur][type] = val;
        for (auto [u, w] : G[cur][type]) {
            if (dist[u][type] > w + val) {
                pq.push({u, w + val});
            }
        } 
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dist[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][0].emplace_back(v, w);
        G[v][1].emplace_back(u, w);
        edge.push_back({u, v, w});
    }
    dijk(1, 0);
    dijk(n, 1);
    
   
    for (auto [x, y, w] : edge) {
        int diff = dist[n][0] - (dist[x][0] + dist[y][1]);
        if (diff < 0) cout << -1 << "\n";
        else
        cout << max(-1ll, w - diff) << "\n"; 
    }
}

