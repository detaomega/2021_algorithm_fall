#include <bits/stdc++.h>
#define int long long
using namespace std;


struct BIT {// 1 - indexed
  vector<int> bit; 
  int n;
  BIT(int sz) : bit(sz + 1), n(sz) {}
  void add(int x, int v) {
    for(int i = x; i <= n; i += i & (-i)) {
      bit[i] += v;
    }
  }
  int ask(int x) {
    int ret = 0;
    for(int i = x; i > 0; i -= i & (-i)) {
      ret += bit[i];
    }
    return ret;
  }
  int ask(int l, int r) {// [l, r]
    if(l > r) return 0;
    return ask(r) - ask(l - 1);
  }
  int kth(int k) {
    int ret = 0;
    for(int i = 1 << __lg(n); i > 0; i >>= 1) {
      if(ret + i <= n && bit[ret + i] < k)
        k -= bit[ret += i];
    }
    return ret + 1;
  }
};

vector<int> qry, vec;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    int i = 0;
    while (cin >> x && x) {
        qry.push_back(x);
        vec.push_back(x);
    }
    sort (vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    BIT bit(vec.size() + 5);
    for (int i = 1; i <= qry.size(); i++) {
        int x = lower_bound(vec.begin(), vec.end(), qry[i - 1]) - vec.begin() + 1;
        bit.add(x, 1);
        if (i == 1) {
            cout << 0 << "\n";
            continue;
        } 
        else {
            int n = i / 2;
            int s1 = vec[bit.kth(n / 2 + 1) - 1];
            int s2 = vec[bit.kth(n / 2) - 1];
            int s3 = vec[bit.kth(n / 2 + (i & 1) + n + 1) - 1];
            int s4 = vec[bit.kth(n / 2 + (i & 1) + n) - 1];

            if (n % 2 == 0) {
        
                int x = (s3 + s4) - (s1 + s2);

                if (x % 2 == 1) {
                    cout << x / 2 << ".5\n";
                }
                else {
                    cout << x / 2 << "\n";
                }
            }
            else {
                cout << s3 - s1 << "\n";
            }
        }

    }
}
