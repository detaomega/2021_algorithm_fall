#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
int val[maxn];

vector<int> G[maxn];

void dfs(int now,int fa) {
    int tmp = 0;
    if (now == 1 && G[now].size() == 0) return;
    if (G[now].size() == 1) return; 
    for (int k : G[now]) {
        if (k != fa) {
            dfs(k, now);
            tmp = tmp + val[k];
            tmp %= mod;
        }
    }
    val[now] = (val[now] * tmp) % mod;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        G[u].push_back(i);
        G[i].push_back(u);
    }
    dfs(1, 0);
    cout << val[1] << "\n";
}

