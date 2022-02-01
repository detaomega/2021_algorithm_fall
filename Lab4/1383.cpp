#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

int arr[maxn], pre[maxn];
int dp[105][105];

int solve(int L,int R) {
    
    if (L > R) return -1e15;
    if (dp[L][R] != -1e15) return dp[L][R]; 
    if (L == R) {
        dp[L][R] = 0;
        return 0;
    }
    else if (R - L == 1) {
        return -1e15;
    }
    else {
        for (int i = L; i < R; i++) {
            for (int j = i + 1; j <= R; j++) {
                
                dp[L][R] = max(solve(L, i) + solve(i + 1, j) + solve(j + 1, R) + (pre[R] - pre[j]) * (pre[i] - pre[L - 1]) - (pre[j] - pre[i]), dp[L][R]);
            }
        }
        return dp[L][R];
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset (dp, -1, sizeof(dp));
    int n;
    cin >> n;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1e15;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    cout << solve(1, n) << "\n";
}

