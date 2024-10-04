#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mts = {{1,0},{0,1},{-1, 0}, {0, -1}};

bool isValid(int i, int j, vector<vector<int>> &ans) {
	int n = ans.size(), m = ans[0].size();
	if(i >= 0 && i < n && j >= 0 && j < m && ans[i][j] == -1) return true;
	return false;
}

vector<vector<int>> nearest(vector<vector<int>> &grid) {
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>> ans(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 1) {
				ans[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while(!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		for(auto mt : mts) {
			int x = tmp.first+mt[0], y = tmp.second+mt[1];
			if(isValid(x, y, ans)) {
				ans[x][y] = ans[tmp.first][tmp.second]+1;
				q.push({x, y});
			}
		}
	}
	return ans;
}


int main() {
	vector<vector<int>> grid = {
		{1,0,0,0},
		{0,0,1,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	vector<vector<int>> ans = nearest(grid);
	for(auto v : ans) {
		for(auto i : v) cout << i << " ";
		cout << endl;
	}
}
























