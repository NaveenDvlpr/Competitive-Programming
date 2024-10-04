#include<bits/stdc++.h>
using namespace std;

bool canBePalindrome(string str, int k) {
	cout << str << " " << k << endl;
	int n = str.length();
	if(n <= 1) return true;
	if(k < 0) return false;
	bool ans = false;
	for(int i = n-1; i > 0; i--) {
		if(str[i] == str[0])
		ans |= canBePalindrome(str.substr(1,i-1),k-(n-1-i));
	}
	ans |= canBePalindrome(str.substr(1), k-1);
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	cout << canBePalindrome(str, k) << endl;
	return 0;
}
