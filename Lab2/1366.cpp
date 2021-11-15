#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 5;

int val[maxn], in[maxn], post[maxn], site[maxn], ans = 0;


int dfs(int l, int r,int L,int R) {
    if (l > r) return -1;
    if (l == r) {
        assert (l == r);
        assert (L == R);
        return in[l];
    }
    int root = post[R];
    int number = site[root] - l;
    int Lson = dfs(l, site[root] - 1, L, L + number - 1);
    int Rson = dfs(site[root] + 1, r, L + number, R - 1);
    if (Lson != -1 && val[Lson] > val[root]) ans++;
    if (Rson != -1 && val[Rson] > val[root]) ans++;
    return root;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        site[ in[i] ] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> post[i];
    }
    dfs(1, n, 1, n);
    cout << ans << "\n";


}

