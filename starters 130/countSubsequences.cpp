#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string word, string ptrn, vector<vector<int>> &dp) {
    int n = word.length(), m = ptrn.length(); 
    if(j == m) return 1;
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    for(int k = i; k < n; k++) {
        if(ptrn[j] == word[k]) ans += solve(k+1, j+1, word, ptrn, dp);    
    }
    return dp[i][j] = ans;
}
int countWays(string s1, string s2) {
	vector<vector<int>> dp(s1.length(), vector<int> (s2.length(), -1));
    return solve(0, 0, s1, s2, dp);
}

int main() {
	string word = "geeksforgeeks", ptrn = "gks";
	cout << countWays(word, ptrn);
	return 0;
}
