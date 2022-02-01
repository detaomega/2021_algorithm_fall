#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e4 + 5;
const int MAXN = 1e6 + 7;
int dp[maxn], val[maxn], w[maxn];
vector<int> years;
int tag[MAXN];


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, x, L, R, occ = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        years.emplace_back(x);
    }
    sort (years.begin(), years.end());
    for (int i = 1; i <= m; i++) {
        cin >> L >> R >> w[i];
        R = upper_bound(years.begin(), years.end(), R) - years.begin() + 1;
        tag[R] += -1;
        L = lower_bound(years.begin(), years.end(), L) - years.begin() + 1;
        tag[L] +=  1; 
        val[i] = R - L;
        for (int j = k; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        tag[i] += tag[i - 1];
        assert (tag[i] >= 0);
        if (!tag[i]) occ++;
    }
    cout << dp[k] + occ << "\n";
        
}

