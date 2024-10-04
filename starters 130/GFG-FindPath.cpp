#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> visited) {
	int n = grid.size(), m = grid[0].size();
	if(x >= 0 && x < n && y >= 0 && y < m) {
		if(grid[x][y] == 3 && visited[x][y] == false) return true;
	}
	return false; 
}

bool isPossible(vector<vector<int>> &grid) {
	int n = grid.size(), m = grid[0].size();
	int x_p, y_p, x_t, y_t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 2) {
				x_p = i;
				y_p = j;
			} else if(grid[i][j] == 1) {
				x_t = i;
				y_t = j;
			}
		}
	}
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[x_p][y_p] = true;
	queue<pair<int,int>> q;
	q.push({x_p, y_p});
	vector<vector<int>> mts = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
	while(!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		for(auto mt : mts) {
			int x = tmp.first+mt[0], y = tmp.second+mt[1]; 
			if(x == x_t && y == y_t) return true;
			if(isValid(x, y, grid, visited)) {
				q.push({x, y});
				visited[x][y] = true;	
			}
		}
	}
	return false;
}


int main() {
	vector<vector<int>> grid = {
		{2, 0, 3, 0, 0},
		{3, 0, 0, 0, 3},
		{3, 3, 3, 3, 3},
		{0, 0, 3, 3, 0},
		{3, 0, 0, 1, 3}
	};
	cout << isPossible(grid);
	return 0;
}




















