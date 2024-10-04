#include<bits/stdc++.h>
using namespace std;

long long int PowMod(long long int x,long long int n,long long int M)
{
	long long ans = 1;
	while(n) {
		if(n&1) {
			ans = (ans*x)%M;
		}
		x = (x*x)%M;
		n >>= 1;
	}
	return ans;	
}


int main() {
	cout << PowMod(2,6,10) << endl;
	return 0;
}
