#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e3 + 5;

int arr[2005][2005];
int dp[2005][2005];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j]; 
            dp[i][j] = -1e15;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[t][i] = arr[t][i];
    }
    for (int i = t - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + arr[i][j]);
            if (j < n) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + arr[i][j]);
            dp[i][j] = max(dp[i][j], dp[i + 1][j] + arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[1][i] << " \n" [i == n];
    }
}

