#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		bool cond = true;
		for(int i = 1; i < n-1 && cond; i++) {
			if(arr[i] < arr[0] || arr[i] < arr[n-1]) cond = false;
		} 
		if(cond) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
