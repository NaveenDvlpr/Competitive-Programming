#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> movements = {
      {1,1},{1,0},{0,1},{-1,-1},
	  {-1, 0}, {0, -1}, {-1, 1}, {1, -1}
    };
    
    bool isValid(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        int n = grid.size(), m = grid[0].size();
        if(i >= 0 && i<n && j >= 0 && j < m && grid[i][j]==1 && visited[i][j] == false) return true;
        return false;
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        cout << i << " - " << j << endl;
		visited[i][j] = true;
        for(auto mt : movements) {
            int i2 = i+mt[0], j2 = j+mt[1];
            cout << i2 << " " << j2 << endl;
            if(isValid(i2, j2, grid, visited)) dfs(i2, j2, grid, visited);        
        }
    }
    
    int numIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islands = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
					islands++;
                    dfs(i, j, grid, visited);
                    cout << "yes" << endl;
                }
            }
        }
        return islands;
    }
    
    
int main() {
	vector<vector<int>> grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};
	cout << numIslands(grid);
	return 0;
}






















