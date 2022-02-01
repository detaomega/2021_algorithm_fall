#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

int dp[maxn], coin[maxn];
int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i < maxn; i++) {
        dp[i] = 1e18;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) cin >> coin[i]; 
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j <= n; j++) {
            if (coin[j] <= i) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    } 
    int T;
    cin >> T;
    while (T--) {
        int tot;
        cin >> tot;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tot -= x * coin[i];
        }
        tot = -tot;
        cout << dp[tot] << "\n";
    }
}

