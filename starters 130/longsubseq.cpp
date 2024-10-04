#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp) {
    	if(i == str1.length() || j == str2.length()) return 0;
    	if(dp[i][j] != -1) return dp[i][j];
    	int ans = 0;
    	if(str1[i] == str2[j]) ans = 1+solve(i+1, j+1, str1, str2, dp);
    	else ans = max(solve(i+1, j, str1, str2, dp),solve(i, j+1, str1, str2, dp));
    	cout << ans << endl;
    	return dp[i][j] = ans;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
	int ls = solve(0, 0, str1, str2, dp);
	
	cout << ls << endl;
	
	return 0;
}
