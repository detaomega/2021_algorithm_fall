#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

struct Dinic {
    struct Edge {
        int to, cap, flow;
        Edge (int _to, int _cap) : to(_to), cap(_cap), flow(0) {}
    };
    vector<int> G[10005];
    vector<Edge> e;
    vector<int> dis, cur;
    int n, s, t;
    Dinic (int sz) : n(sz + 5), dis(sz + 4), cur(sz + 5) {}
    void add(int u, int v, int f) {
        G[u].emplace_back(e.size());
        e.emplace_back(v, f);
        G[v].emplace_back(e.size());
        e.emplace_back(u, 0);
    }
    int dfs(int x, int f) {
        if (x == t || f == 0) return f;
        for (int &i = cur[x]; i < (int)G[x].size(); i++) {
            int k = G[x][i];
            if (dis[e[k].to] == dis[x] + 1 && e[k].flow != e[k].cap) {
                int df = dfs(e[k].to, min(f, e[k].cap - e[k].flow));
                if (df) {
                    e[k].flow += df;
                    e[k ^ 1].flow -= df;
                    return df;
                }
            }
        }
        return 0;
    }
    bool bfs() {
        dis.assign(dis.size(), -1);
        queue<int> q;
        dis[s] = 0;
        q.push(s);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int k : G[x]) {
                if (e[k].cap != e[k].flow && dis[e[k].to] == -1) {
                    q.push(e[k].to);
                    dis[e[k].to] = dis[x] + 1;
                }
            }
        }
    
        return (dis[t] != -1);
    } 
    int solve(int _s, int _t) {
        s = _s;
        t = _t;
        int df, flow = 0;
        while (bfs()) {
            cur.assign(cur.size(), 0);
            while ((df = dfs(s, INT_MAX))) flow += df;

        }
        return flow;
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int F, N, M;
    cin >> F >> N >> M;
    int S = 0, T = F + 2 * N + M + 1;
    Dinic dinic(T + 5);
    for (int i = 1; i <= F; i++) {
        int cap;
        cin >> cap;
        dinic.add(0, i, cap);
    }
    for (int i = 1; i <= N; i++) {
        int cap;
        cin >> cap;
        dinic.add(i + F, i + F + N, cap);
    }
    for (int i = 1; i <= M; i++) {
        int cap;
        cin >> cap;
        dinic.add(i + 2 * N + F, T, cap);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v, cap;
        cin >> u >> v >> cap;
        dinic.add(u, v + F, cap);
    }
    cin >> Q;
    while (Q--) {
        int u, v, cap;
        cin >> u >> v >> cap;
        u = F + N + u;
        v = F + 2 * N + v;
        dinic.add(u, v, cap);
    }
    int k;
    cin >> k;

    cout << min(k, dinic.solve(S, T)) << "\n";
     
}

