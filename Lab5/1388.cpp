#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;


set<pair<int,int>> edge;
int p[maxn];

struct Qry {
    int type, u, v;
};

vector<Qry> events;

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

void merge(int u, int v) {
    u = f(u);
    v = f(v);
    if (u != v) p[u] = v;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, Q;
    cin >> n >> m >> Q;
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edge.insert ({u , v});
    }
    for (int i = 0; i < Q; i++) {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == 'A') {
             events.push_back({0, u, v});
        }
        else{
            if (u > v) swap(u, v);
            events.push_back({1, u, v});
            edge.erase({u, v});
        }
    }
    for (auto [x, y] : edge) {
        merge(x, y);
    }
    vector<string> ans;
    reverse(events.begin(), events.end());
    for (auto [type, u, v] : events) {
        if (type == 0) {
            if (f(u) == f(v)) ans.push_back("YES");
            else ans.push_back("NO");
        }
        else {
            merge(u, v);
        }
    }
    reverse(ans.begin(), ans.end());
    for (string k : ans) cout << k << "\n";
}

