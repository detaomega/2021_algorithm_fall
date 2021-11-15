#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 5;

int arr[maxn];

int pre[maxn];

int get_val(int l,int r) {
    int Mn = 0;
    vector<int> vec;
    for (int i = l; i <= r; i++) vec.push_back(arr[i]);
    int m = (r - l) >> 1;
    nth_element(vec.begin(), vec.begin() + m, vec.end()); 
    for (int i = l; i <= r; i++) Mn += abs(vec[m] - vec[i - l]);
    return Mn;
}

int solve(int l,int r) {
    if (r - l <= 1) return 0;
    else {
        int m = (l + r) >> 1;
        return min(solve(l, m) + get_val(m + 1, r), solve(m + 1, r) + get_val(l, m));
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
    cout << solve(1, n) << "\n";


}

