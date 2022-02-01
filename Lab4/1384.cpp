#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;

int dp[maxn];

int32_t main() {
    int t;
    cin >> t;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < maxn; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 + dp[i - 3]) % mod;
    }
    while (t--) {
        int x;
        cin >> x;
        cout << ((dp[x] - 1)* 4 + 1)% mod << "\n";
    }
}

