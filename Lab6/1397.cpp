#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

struct Edge {
    int u, v, w;
};

vector<Edge> e;
int n, m;

bool check(int k) {
    vector<int> dist(n + 5, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (-e[j].w >= k) continue;
            if (dist[e[j].v] > dist[e[j].u] + e[j].w) {
                if (i == n - 1) return false;
                dist[e[j].v] = dist[e[j].u] + e[j].w;
            }
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Mn = -1e15, Mx = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
        if (w < 0) {
            Mn = max(Mn, w);
            Mx = min(Mx, w);
        }
    }
    if (check(-Mx + 1) == true) {
        cout << "GO AHEAD\n";
    }
    else {
        int L = 0, R = 1e9, ans;
        while (L + 1 < R) {
             int m = (L + R) >> 1;
            if (check (m)) {
                L = m;
                ans = m;
            }
            else {
                R = m;
                ans = m - 1;
            }
        }
 
        if (-ans == Mn) cout << "NO WAY BACK\n";
        else cout << -ans << "\n";
    }
}

