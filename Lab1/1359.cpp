#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

int n, k;
pair<int,int> arr[maxn];
char getc(){
	static const int bufsize = 1<<16;
	static char B[bufsize], *S=B, *T=B;
	return (S==T&&(T=(S=B)+fread(B,1,bufsize,stdin),S==T)?0:*S++);
}

template <class T>
bool input(T& a){
	a=(T)0;
	register char p;
	while ((p = getc()) < '-')
		if (p==0 || p==EOF) return false;
	if (p == '-')
		while ((p = getc()) >= '0') a = a*10 - (p^'0');
	else {
		a = p ^ '0';
		while ((p = getc()) >= '0') a = a*10 + (p^'0');
	}
	return true;
}

template <class T, class... U>
bool input(T& a, U&... b){
	if (!input(a)) return false;
	return input(b...);
}

bool check(double K) {
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        // cout << (int)arr[i].F / K - arr[i].S << "\n";
        if ((int)arr[i].F / K - arr[i].S < 0)
            continue;
        tot += ((int)(arr[i].F / K) - arr[i].S);
    }
    //cout << tot << "\n";
    return tot >= k;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        input(arr[i].F);
        input(arr[i].S);
    }
    double l = 0, r = 5e9;
    double ans = 0;
    
    for (int i = 0; i <= 53; i++) {
    
        double m = (l + r) / 2.0;
        if (check(m)) {
            l = m;
        }
        else {
            r = m;
        }
        //printf ("%.6lf %.6lf\n", l, m);
    }
    printf ("%.10lf", r);
}

