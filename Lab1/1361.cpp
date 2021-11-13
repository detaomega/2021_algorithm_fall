#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

vector<int> vec;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort (vec.begin(), vec.end());
    
    int Q;
    cin >> Q;
    while (Q--) {
        int Min, Max, ans = 0;
        cin >> Min >> Max;
        for (int i = 1; i < k; i++) {
            int l = Min * i, r = min(Max, (i + 1) * Min - 1);
            if (l > Max) break;
            ans += i * ((upper_bound(vec.begin(), vec.end(), r) - vec.begin()) - (lower_bound(vec.begin(), vec.end(), l) - vec.begin()));
        }
        if (k * Min <= Max)
        ans += k * ((upper_bound(vec.begin(), vec.end(), k * Min) - vec.begin()) - (lower_bound(vec.begin(), vec.end(), k * Min) - vec.begin()));
        cout << ans << "\n";
    }

}

