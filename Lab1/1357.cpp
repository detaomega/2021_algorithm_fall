#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

vector<int> vec;

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int ans = 1;
    sort (vec.begin(), vec.end());
    int pos = n;
    for (int i = 0; i < n; i++) {
        ans = (ans * min(vec[i] - i, pos)) % mod;
        pos--;
    }
    cout << ans << "\n";

}

