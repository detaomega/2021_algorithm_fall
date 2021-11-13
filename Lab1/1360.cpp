#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

string s[] = {"GRYFFINDOR", "HUFFLEPUFF", "RAVENCLAW", "SLYTHERIN"};

string Cmp[4];

int cnt[26];

struct Student {
    string name;
    int score[4];
};

vector<Student> vec[4];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cnt['G' - 'A'] = 0;
    cnt['H' - 'A'] = 1;
    cnt['R' - 'A'] = 2;
    cnt['S' - 'A'] = 3;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < 4; i++) cin >> Cmp[i];
    for (int i = 1; i <= n; i++) {
        int mx = 0, id = 0;
        Student x;
        cin >> x.name;
        for (int j = 0; j < 4; j++) {
            cin >> x.score[j];
            if (mx < x.score[j]) {
                id = j;
                mx = x.score[j];
            }
        }
        vec[id].push_back(x);
    }
    for (int i = 0; i < 4; i++) {
        sort (vec[i].begin(), vec[i].end(), [&](Student a, Student b) {
            for (int k = 0; k < 4; k++) {
                if (a.score[cnt[ Cmp[i][k] - 'A'] ] != b.score[cnt[ Cmp[i][k] - 'A'] ])
                    return a.score[cnt[ Cmp[i][k] - 'A'] ] > b.score[cnt[ Cmp[i][k] - 'A']];
            }
            return a.name <= b.name;
        });
    }
    for (int i = 0; i < 4; i++) {
        cout << s[i] << ":";
        if (vec[i].size() == 0) cout << " NO NEW STUDENTS\n";
        else cout << "\n";
        for (auto k : vec[i]) {
            cout<< k.name << "\n";
        }
    }
                



}

