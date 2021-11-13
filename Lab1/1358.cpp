#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

vector<int> vec;

unordered_map<int,int> mp;


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        vec.push_back(x);
    }
    sort (vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    int ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        int pos = n - 1;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] == vec[j]) continue;
            if (vec[pos] <= vec[j]) break;
            while (vec[pos] + vec[i] + vec[j] > w && vec[pos] > vec[j]) pos--;
            if (vec[pos] <= vec[j]) break;
            if (vec[pos] + vec[i] + vec[j] == w) ans++;
                
        }
    }
    
    for (int i = 0; i < vec.size(); i++) {
        if ((w - vec[i]) % 2 == 0) {
            int tot = mp[(w - vec[i]) / 2];
             ans = ans + (tot >= 2);
        }
    }
    if (ans == 0) {
        cout << "FeiDooDoo_Zuo_Wei_Men\n";
    }
    else
        cout << ans << "\n";

}
