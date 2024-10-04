#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mts = {{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(int i, int j, vector<vector<char>> &inpMar, vector<vector<char>> &opMar) {
	int n = inpMar.size();
	int m = inpMar[0].size();
	if(i > 0 && i < n-1 && j > 0 && j < m-1 && inpMar[i][j] == 'O' && opMar[i][j] == 'X') return true;
	return false;
}

void dfs(int i, int j, vector<vector<char>> &inpMar, vector<vector<char>> &opMar) {
	opMar[i][j] = 'O';
	for(auto mt : mts) {
		int i2 = i+mt[0], j2 = j+mt[1];
		if(isValid(i2, j2, inpMar, opMar)) dfs(i2, j2, inpMar, opMar);
	}
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> &mar) {
	vector<vector<char>> ans(n, vector<char> (m, 'X'));
	for(int j = 0; j < m; j++) {
		if(mar[0][j] == 'O') dfs(0, j, mar, ans);
		if(mar[n-1][j] == 'O') dfs(n-1, j, mar, ans);
	} 
	for(int j = 0; j < n; j++) {
		if(mar[j][0] == 'O') dfs(j, 0, mar, ans);
		if(mar[j][m-1] == 'O') dfs(j, m-1, mar, ans);
	}
	return ans;
}

int main() {
	vector<vector<char>> mar = {
		{'X','O','X','O'},
		{'X','O','X','X'},
		{'X','X','O','X'},
		{'X','O','X','X'},
		{'X','X','O','O'}
	};
	vector<vector<char>> ans = fill(5, 4, mar);
	for(auto v : ans) {
		for(auto c : v) cout << c << " ";
		cout << endl;
	}
	return 0;
}

















