#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

struct Node {
    int k, x, score;
    double get;
    void calc() {
        if (k == 0) {
            if (x == 0) get = score;
            else get = 0;
        } 
        else
            get = score * double (k) / double (k + x) - score * double (k) / double (k + x + 1);
    }
    bool operator < (const Node &cmp) const {
        return cmp.get > get;
    }
};
priority_queue<Node> pq;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> zero;
    for (int i = 1; i <= n; i++) {
        int c, p;
        cin >> c >> p;
        Node now;
        now.k = p;
        now.x = 0;
        now.score = c;
        now.calc();
        pq.push(now);
    }
          
    double ans = 0;
    for (int i = 0; i < k; i++) {
        auto it = pq.top();
           pq.pop();
        it.x++;
        it.calc();
        pq.push(it);
    }
    while (pq.size()) {
        auto it = pq.top();
        pq.pop();
        if (it.x == 0) continue;
        ans = ans + it.score * double (it.x) / double (it.k + it.x);
    }
    printf ("%.10lf\n", ans);

    

}

