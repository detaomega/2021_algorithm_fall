#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e3 + 5;

int T = 1;
struct Node {
    string s;
    int w, id;
    bool operator < (const Node &cmp) const {
        if (cmp.w == w) {
            return cmp.s < s;
        }
        else {
            return cmp.w < w;
        }
    }
};

vector<string> vec[maxn];
priority_queue<Node> pq;
unordered_map<string,int> mp, val;

int L[maxn * 2], R[maxn * 2];
string node[maxn];

void dfs(int now,int dep) {
    if (L[now] == -1 && R[now] == -1) {
        val[node[now]] = dep;
    }
    else {
        if (L[now] != -1) dfs (L[now], dep + 1);
        if (R[now] != -1) dfs (R[now], dep + 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m = 0;
    string s;
    cin >> n;
    getline(cin, s);
    memset (L, -1, sizeof (L));
    memset (R, -1, sizeof (R));
    for (int i = 1; i <= n; i++) {
        string tmp = "";
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                vec[i].push_back(tmp);
                mp[tmp]++;
                tmp = "";
            }
            else {
                tmp = tmp + s[j];
            }
        }
        assert (tmp != "");
        mp[tmp]++;
        vec[i].push_back(tmp);
    }
    for (auto k : mp) {
        Node now;
        now.s = k.first;
        now.w = k.second;
        now.id = T++;
        node[now.id] = now.s;
        pq.push(now);
        m++;
    }
    while (pq.size() > 1) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        Node now;
        now.s = min(a.s, b.s);
        now.w = a.w + b.w;
        now.id = T++;
        pq.push(now);
        L[now.id] = a.id;
        R[now.id] = b.id;
    }
    dfs (T - 1, 0);
    m = __lg(m - 1) + 1;
    for (int i = 1; i <= n; i++) {
        int a = m * vec[i].size();
        int b = 0;
        for (string a : vec[i]) {
            b = b + val[a];
        }
        double ans = b / double (a);
        printf ("%.8lf\n", ans);
    }
}

