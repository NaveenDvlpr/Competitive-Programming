#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> cost_x, vector<int> cost_y) {
	sort(cost_x.begin(), cost_x.end());
	sort(cost_y.begin(), cost_y.end());
	int x_sum = 0;
	for(auto i : cost_x) x_sum += i;
	int y_sum = 0;
	for(auto i : cost_y) y_sum += i;
	cout << x_sum << " " << y_sum << endl;
	int i = 0, j = 0, h = 1, v = 1;
	int n = cost_x.size(), m = cost_y.size();
	int ans = 0;
	while(!(i == n && j == m)) {
		if(i == n) {
			ans += (cost_y[j]*h);
			j++;
		} else if (j == m) {
			ans += (cost_x[i]*v);
			i++;
		}
		else if(x_sum*(v+1) < y_sum*(h+1)) {
			ans += (cost_y[j]*h);
			v++;
			y_sum -= cost_y[j];
			j++;
		} else if(x_sum*(v+1) > y_sum*(h+1)) {
			ans += (cost_x[i]*v);
			h++;
			x_sum -= cost_x[i];
			i++;
		} else {
			if(cost_x[i]*v < cost_y[j]*h) {
				ans += (cost_x[i]*v);
				h++;
				x_sum -= cost_x[i];
				i++;
			} else {
				ans += (cost_y[j]*h);
				v++;
				y_sum -= cost_y[j];
				j++;
			}
		}
	}
	return ans;
}

int main() {
	vector<int> x = {2, 1, 3, 1, 4};
	vector<int> y = {4, 1, 2};
	cout << solve(x, y);
	
	
	return 0;
}






















