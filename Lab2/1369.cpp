#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

vector<int> vec;


vector<int> sequence[20];

void solve(int k) {
    if (sequence[k].size()) return;
    if (k == 0) {
        sequence[k].push_back(1);
    }
    else {
        solve(k - 1);
        for (int x : sequence[k - 1]) sequence[k].push_back(x + (1 << (k - 1)));
        reverse(sequence[k - 1].begin(), sequence[k - 1].end());
        for (int x : sequence[k - 1]) sequence[k].push_back(x);
    }
}

int32_t main() {
    int n;
    cin >> n;
    solve(n);
    for (int k : sequence[n]) cout << k << " ";
    cout << "\n";

}

