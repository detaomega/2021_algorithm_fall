#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

struct Dsu {
    int p[maxn], sz;
    void init (int n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        sz = n;
    }
    int f(int x) {
        return p[x] == x ? x : p[x] = f(p[x]);
    }

    bool merge(int x,int y) {
        x = f(x);
        y = f(y);
        if (x == y) return false;
        p[x] = y;
        sz--;
        return true;
    }
} Dsu[2];

vector<pair<int,int>> edge_1, edge_2;


void solve() {
    int n, m, k, F, S;
    edge_1.clear();
    edge_2.clear();
    cin >> n >> m >> k >> F >> S;
    for (int i = 1; i <= m; i++) {
        int u, v;
        char type;
        cin >> u >> v >> type;
        if (type == 'F') {
            edge_1.emplace_back(u, v);
        }
        else {
            edge_2.emplace_back(u, v);
        }
    }
    //ax + by = k;
    //x + y = n - 1;
    if (S == F) {
        if (k % F) cout << "No\n";
        else {
            int need = k / F;
            if (need != n - 1) {
                cout << "No\n";
                return;
            }
            Dsu[0].init(n);
            for (auto [u, v] : edge_1) {
                Dsu[0].merge(u, v);
            }
            for (auto [u, v] : edge_2) {
                Dsu[0].merge(u, v);
            }
            if (Dsu[0].sz != 1) cout << "No\n";
            else cout << "Yes\n";
        }
        return;
    }
    int y = (k - (n - 1) * F) / (S - F);
    int x = (k - (n - 1) * S) / (F - S);
    if (x + y != n - 1 || F * x + S * y != k) {
        cout << "No\n";
        return;
    }
    int cnt = 0;
    Dsu[0].init(n);
    Dsu[1].init(n);
    for (auto [u, v] : edge_1) {
        Dsu[0].merge(u, v);
    }
    for (auto [u, v] : edge_2) {
        if (cnt == y) break;
        if (Dsu[0].merge(u, v) && Dsu[1].merge(u, v)) {
            cnt++;
        }
    }
    if (Dsu[0].sz != 1) {
        cout << "No\n";
        return;
    }
    Dsu[0].init(n);
    Dsu[1].init(n);
    cnt = 0;
    for (auto [u, v] : edge_2) {
        Dsu[0].merge(u, v);
    }
    for (auto [u, v] : edge_1) {
        if (cnt == x) break;
        if (Dsu[0].merge(u, v) && Dsu[1].merge(u, v)) {
            cnt++;
        }
    }
    if (Dsu[0].sz != 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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

