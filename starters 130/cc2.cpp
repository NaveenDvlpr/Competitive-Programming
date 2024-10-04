#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int k, unordered_map<int, int> &mp) {
	if(a == b) return 0;
	if(a > b) return INT_MAX;
	if(mp[a] != 0) return mp[a];
	int ans = INT_MAX;
	if(a < b && a*k > b) {
		ans = min(ans, b-a);
	} else {
		ans = min(solve(a+1,b, k), solve(a*k, b, k))+1;
	}
	return mp[a] = ans;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, k;
		cin >> a >> b >> k;
		unordered_map<int, int> mp;
		cout << solve(a,b,k,mp) << endl;	
	}
	
	return 0;
}
