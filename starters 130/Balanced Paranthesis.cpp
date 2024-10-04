#include<bits/stdc++.h>
using namespace std;

void solve(int o,int c, string &str, vector<string> &ans) {
	if(c == 0 && o == 0) {
		ans.push_back(str);	
	}
	else if(c == o) {
		str.push_back('(');
		solve(o-1, c, str, ans);
		str.pop_back();
	} else {
		
		if(o > 0) {
			str.push_back('(');
			solve(o-1, c, str, ans);
			str.pop_back();	
		}
		if(c > 0) {
			str.push_back(')');
			solve(o, c-1, str, ans);
			str.pop_back();	
		}
	}
}

int main() {
	vector<string> ans;
	string str = "";
	int n; 
	cin >> n;
	solve(n, n, str, ans);
	
	for(auto str: ans) cout << str << endl;
}
