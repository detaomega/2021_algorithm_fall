#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define big(x) (x>='A' && x<='Z')
#define small(x) (x>='a' && x<='z')
#define Num(x) (x>='0' && x<='9')


vector<pair<string,int> > ans;
queue<char> q;
map<string,int> mp;

main() {
	string s, tmp = "";
	int num = 0;
	cin >> s;
	for(char c:s) {
		q.push(c);
	}
	while(q.size()) {
		char c = q.front();q.pop();
		if(big(c)) {
			if(tmp.size() > 0) {
				if(!num)
					ans.push_back({tmp, 1});
				else
					ans.push_back({tmp, num});
				num = 0;
			}
			tmp.clear();
			tmp += c;
		}
		else if(small(c)) {
			tmp += c;
		}
		else if(Num(c)) {
			num *= 10;
			num += (c-'0');
		}
		else if(c == '(') {
			if(tmp.size() > 0) {
				if(!num)
					ans.push_back({tmp, 1});
				else
					ans.push_back({tmp, num});
				num = 0;
			}
			tmp.clear();
			string cc = "(";
			ans.push_back({cc, 0});
		}
		else {
			if(tmp.size() > 0) {
				if(!num)
					ans.push_back({tmp, 1});
				else
					ans.push_back({tmp, num});
				num = 0;
			}
			tmp.clear();
			int mul = 0;
			while(q.size() && Num(q.front())) {
				mul *= 10;
				mul += (q.front()-'0');
				q.pop();
			}
			if(!mul) mul = 1;
			vector<pair<string,int> > ttmp;
			while(ans.back().X != "(") {
				ttmp.push_back({ans.back().X, ans.back().Y * mul});
				ans.pop_back();
			}
			ans.pop_back();
			while(ttmp.size()) {
				ans.push_back(ttmp.back());
				ttmp.pop_back();
			}
		}
	} 
	
	if(tmp.size() > 0) {
		if(!num)
			ans.push_back({tmp, 1});
		else
			ans.push_back({tmp, num});
		num = 0;
	}
	for(auto a:ans) {
		if(mp.find(a.X) == mp.end()) {
			mp[a.X] = 0;
		}
		mp[a.X] += a.Y;
	}
	vector<pair<string,int> > vec[2];
	for(auto a:mp) {
	    if (a.X.size() == 2) vec[1].push_back({a.X, a.Y});
        else vec[0].push_back({a.X, a.Y});
    }
    cout << vec[0].size() << "\n";
    for (auto a : vec[0]) cout << a.first << ":" << a.second << "\n";
    cout << vec[1].size() << "\n";
    for (auto a : vec[1]) cout << a.first << ":" << a.second << "\n";

}

