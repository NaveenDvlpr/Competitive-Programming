#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mts = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, vector<vector<int>> &grid) {
	int n = grid.size(), m = grid[0].size();
	if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) return true;
	return false;
}

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) q.push({i, j});
        }
    }
    int ans = 0;
    while(!q.empty()) {
        queue<pair<int,int>> q2;
        while(!q.empty()) {
        	pair<int, int> tmp = q.front();
        	q.pop();
        	int i = tmp.first, j = tmp.second;
        	for(auto mt : mts) {
        		int i2 = i+mt[0], j2 = j+mt[1];
				if(isValid(i2, j2, grid)) {
					grid[i2][j2] = 2;
					q2.push({i2, j2});
				} 
			}
		}
		if(!q2.empty()) {
			ans++;
			q = q2;
		}
    }
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		if(grid[i][j] == 1) {
    			return -1;
			}
		}
	}
    return ans;
}

int main() {
	vector<vector<int>> grid = {{2,2,2,2}};
	cout << orangesRotting(grid) << endl;
	return 0;
}
























