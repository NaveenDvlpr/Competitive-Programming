#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;
    
    int power(int a, int b) {
        int ans = 1;
        while(b) {
            if(b&1) ans = (ans*1LL*a)%mod;
            a = (a*1LL*a)%mod ;
            b >>= 1;
        }
        return ans;
    }
    
    int solve(int choice, int size, vector<vector<int>> &dp) {
        if(size == 0) return 1;
        if(dp[choice][size] != -1) return dp[choice][size];
        int ans = solve(0, size-1, dp);
        if(choice == 0) ans = (ans+0LL+solve(1, size-1, dp))%mod;
        return dp[choice][size] = ans;
    }
    
    int numberOfConsecutiveOnes(int n) {
        if(n == 2) return 1;
        vector<vector<int>> dp(2, vector<int>(n, -1));
        int total = power(2, n);
        int noncc = (solve(0, n-1, dp)+0LL+solve(1, n-1, dp))%mod;
        int ans = (total+0LL-noncc+mod)%mod;
        cout << total << " " << noncc << " " << ans << endl;
		return ans;
    }


int main() {
	cout << numberOfConsecutiveOnes(10) << endl;
	return 0;
}
