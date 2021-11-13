#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

multiset<int> s;
vector<int> vec;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, L;
    cin >> n >> k >> L; 
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        vec.push_back(x);
    }
    int cnt = 0;
    sort (vec.begin(), vec.end());
    for (int i = n - 1; i >= 0; i--) {
        if (s.count(vec[i]) == false) continue;
        auto it = s.find(vec[i]);
        s.erase(it);
        cnt++;
        if (s.size() == 0) break;
        if (*s.begin() <= k - vec[i]) {
            it = s.lower_bound(k - vec[i] + 1);
            it = prev(it);
            s.erase(it);
        }
    }
    cout << cnt * L * 2 << "\n";
}

