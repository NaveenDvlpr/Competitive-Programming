#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mts = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
    };
    
    bool isValid(int i, int j, vector<vector<int>> &board) {
        int n = board.size();
        if(i > 0 && i < n && j > 0 && j < n && board[i][j] == -1) return true;
        return false;
    } 
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int x_k = KnightPos[0], y_k = KnightPos[1], x_t = TargetPos[0], y_t = TargetPos[1];
	    vector<vector<int>> board(N+1, vector<int>(N+1, -1));
	    queue<pair<int, int>> q;
	    q.push({x_k, y_k});
	    board[x_k][y_k] = 0;
	    while(1) {
	        pair<int, int> tp = q.front();
	        q.pop();
	        int x_p = tp.first, y_p = tp.second;
	        for(auto mt : mts) {
	            int x_n = x_p+mt[0], y_n = y_p+mt[1];
	            if(isValid(x_n, y_n, board)) {
	                board[x_n][y_n] = board[x_p][y_p]+1;
	                if(x_n == x_t && y_n == y_t) return board[x_n][y_n];
	                q.push({x_n, y_n});
	            }
	        }
	    }
	}

int main() {
	vector<int> k = {4, 5}, t = {1,1};
	cout << minStepToReachTarget(k, t, 6);
	return 0;
}
