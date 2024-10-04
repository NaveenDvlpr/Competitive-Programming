#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y) {
	if(n == x || n == y || n == 1) return true;
	if(n < 1) return false;
	bool ans = true;
	ans &= solve(n-x, x, y);
	ans &= solve(n-y, x, y);
	ans &= solve(n-1, x, y);
	return !ans;
}

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	cout << solve(n, x, y) << endl;
	return 0;
}
