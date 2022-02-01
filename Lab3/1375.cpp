#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

vector<pair<int,int> > vec;
int32_t main() {
    int n, p; 
    cin >> n >> p;
    int L, R;
    cin >> L >> R;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (r < L || l > R) continue;
        else {
            if (l < L) l = L;
            if (r > R) r = R;
            vec.push_back({l, r});
        } 
    }
    sort (vec.begin(), vec.end(), [] (pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    });
    int Rest = 0, ans = 1;
    if (vec.front().first > L) {
        cout << 0 << "\n";
        return 0;
    }
    Rest = vec.front().second;
    pair<int,int> lst;
    int mx = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].first > Rest) {
            if (mx < Rest) {
                cout << 0 << "\n";
                return 0;
            }
            else {
                ans++;
                Rest = mx;
            }

        }
        mx = max(mx, vec[i].second);
    }
    if (Rest != R) {
        mx = max(mx, Rest);
        ans++;
    } 
    if (Rest == R) {
        cout << ans * p << "\n";
    }
    else {
        cout << 0 << "\n";
    }

}

