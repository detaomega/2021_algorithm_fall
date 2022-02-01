#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;

int dp[maxn][2], arr[maxn];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> arr[i];
        x = arr[i];
        if (tmp.size() == 0 || tmp.back() < x) {
            tmp.emplace_back(x);
            dp[i][0] = tmp.size();
        }
        else {
            int it = lower_bound (tmp.begin(), tmp.end(), x) - tmp.begin();
            tmp[it] = x;
            dp[i][0] = it + 1;
        }
    }
    tmp.clear();
    for (int i = n; i >= 1; i--) {
        int x = arr[i];
        if (tmp.size() == 0 || tmp.back() < x) {
            tmp.emplace_back(x);
            ans = max((int)tmp.size() - 1 + dp[i][0], ans);
        }
        else {
            int it = lower_bound (tmp.begin(), tmp.end(), x) - tmp.begin();
            tmp[it] = x;
            ans = max(it + dp[i][0], ans);
        }
    }
    tmp.clear();
    for (int i = 1; i <= n; i++) {
        int x = -arr[i];
        if (tmp.size() == 0 || tmp.back() < x) {
            tmp.emplace_back(x);
            dp[i][0] = tmp.size();
        }
        else {
            int it = lower_bound (tmp.begin(), tmp.end(), x) - tmp.begin();
            tmp[it] = x;
            dp[i][0] = it + 1;
        }
    }
    tmp.clear();
    for (int i = n; i >= 1; i--) {
        int x = -arr[i];
        if (tmp.size() == 0 || tmp.back() < x) {
            tmp.emplace_back(x);
            ans = max((int)tmp.size() - 1 + dp[i][0], ans);
        }
        else {
            int it = lower_bound (tmp.begin(), tmp.end(), x) - tmp.begin();
            tmp[it] = x;
            ans = max(it + dp[i][0], ans);
        }
    }
    cout << ans << "\n";


}

