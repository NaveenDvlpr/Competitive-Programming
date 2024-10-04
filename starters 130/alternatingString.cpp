#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		char last = str[n-1];
		int ans = 0;
		for(int i = n-2; i >= 0; i--) {
			if(str[i] == last) ans++;
			last = str[i];
		}
		cout << ans << endl;
	}	
	return 0;
}
