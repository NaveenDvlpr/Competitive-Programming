#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mts = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isValid(int i, int j, vector<vector<int>> &image, int color) {
	int n = image.size(), m = image[0].size();
	if(i >= 0 && i < n && j >= 0 && j < m && image[i][j] == color) return true;
	return false;
}

void dfs(int i, int j, vector<vector<int>> &image, int newColor) {
	int oldColor = image[i][j];
	image[i][j] = newColor;
	for(auto mt : mts) {
		int i2 = i+mt[0], j2 = j+mt[1];
		if(isValid(i2, j2, image, oldColor)) dfs(i2, j2, image, newColor);
	}
}

vector<vector<int>> floodfill(vector<vector<int>> &image, int sr, int sc, int newColor) {
	if(image[sr][sc] == newColor) return image;
	dfs(sr, sc, image, newColor);
	return image;
}

int main() {
	vector<vector<int>> image = {{1,1,1}, {1,1,0},{1,0,1}};
	image = floodfill(image, 0, 0, 0);
	for(auto v : image) {
		for(auto j : v ) cout << j << " ";
		cout << endl;
	}
	return 0;
}






















