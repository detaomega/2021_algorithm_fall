#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

bool occ[maxn] = {};
int arr[maxn];
int cnt[maxn], nxt[maxn], last[maxn];

struct Node {
    int out, id;
    bool operator < (const Node &cmp) const {
        return cmp.out > out;
    }
};

priority_queue<Node> pq;
vector<int> vec;
int32_t main() {
    int N, C, Q;
    cin >> N >> C >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        if (vec.size() == 0 || vec.back() != x) vec.push_back(x);
        last[x] = maxn;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
        nxt[i] = last[vec[i]];
        last[vec[i]] = i;
    }
    int ans = 0, Cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (occ[vec[i]] == false) { 
            
            ans++;
        
            if (Cnt == C) {
                while (pq.top().out <= i) pq.pop();
                auto it = pq.top(); pq.pop();
                occ[it.id] = false;
                occ[vec[i]] = true;
            } 
            else {
                Cnt++;
                occ[vec[i]] = true;
            }
            
        }
        pq.push({nxt[i], vec[i]});
    }
    cout << ans << "\n";
}
