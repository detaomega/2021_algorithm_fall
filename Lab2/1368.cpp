#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

int fast_pow(int a,int k) {
    int ret = 1;
    while (k) {
        if (k & 1) {
            ret = ret * a % mod;
        }
        a = (a * a) % mod;
        k >>= 1;
    }
    return ret;
}
int32_t main() {
    int a, b, Q;
    cin >> a >> b >> Q;
    while (Q--) {
        int n;
        cin >> n;
        cout << ((fast_pow(a, n - 1) + (b * ((fast_pow(a, n - 1) - 1) * fast_pow(a - 1, mod - 2) % mod)) % mod) % mod + mod) % mod << "\n";
    }



}

