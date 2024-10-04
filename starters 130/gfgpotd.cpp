#include<bits/stdc++.h>
using namespace std;

int status(int i, vector<int> &a) {
	int n = a.size();
	bool before = true, after = true;
	if(i-1 >= 0 && a[i-1] > a[i]) before = false; 
	if(i+1 < n && a[i+1] > a[i]) after = false;
	if(before && after) return 0;
	if(before && !after) return 1;
	return 2; 
}


int solve(vector<int> &a) {
	int n = a.size();
	int l = -1, h = n;
	while(1) {
		int m = (l+h)/2;
		int s = status(m, a);
		if(s == 0) return a[m];
		else if(s == 1) l = m;
		else h = m;
	}
}

int main() {
	vector<int> a = {1,2,3,4,5,6,5,4,3,2,1};
	cout << solve(a) << endl;
	return 0;
}
