#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;

int money[] = {1000, 500, 100, 50, 10, 5, 1};

int arr[maxn];
void solve() {
    int n;
    cin >> n;
    int cnt[7] = {};
    for (int i = 1; i <= n; ++i) {
        int tot, give = 0;
        cin >> tot;
        for (int j = 0; j < 7; j++) {
            int x;
            cin >> x;
            give += x * money[j];
            cnt[j] += x;
        }
        arr[i] = give - tot;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 7; j++) {
            if (arr[i] == false) break;
            int need = min(arr[i] / money[j], cnt[j]);
            cnt[j] -= need;
            arr[i] -= need * money[j];
        }
        if (arr[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


}

