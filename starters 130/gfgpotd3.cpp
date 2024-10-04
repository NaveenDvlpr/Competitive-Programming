#include<bits/stdc++.h>
using namespace std;

vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
    int small = -1, tmp = arr.size(), big = arr.size();
    while(tmp-small > 1) {
    	int mid = (tmp+small)/2;
    	if(arr[mid] >= x) tmp = mid;
    	else small = mid;
	}
	tmp = -1;
	while(big-tmp > 1) {
		int mid = (tmp+big)/2;
		if(arr[mid] <= x) tmp = mid;
		else big = mid;
	}
	
	cout << small << " " << big << endl;
	
	vector<int> ans;
	while(k--) {
		if(small == -1) ans.push_back(arr[big++]);
		else if(big == n) ans.push_back(arr[small--]);
		else {
			if(abs(x-arr[big]) <= abs(x-arr[small])) ans.push_back(arr[big++]);
			else ans.push_back(arr[small--]);
		}
	}
	return ans;
}

int main() {
	vector<int> arr = {1, 2, 3, 6, 10};
	vector<int> ans = printKClosest(arr, 5, 3, 4);
	for(auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
