#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

int dist[505][505];

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else
                dist[i][j] = 1e15;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == 1e15) cout << -1 << "\n";
        else cout << dist[u][v] << "\n";
    }
}

