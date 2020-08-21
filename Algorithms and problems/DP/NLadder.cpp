// we are given a ladder of n steps we can take 1 , 2, 3 steps at a time 
#include <iostream>

using namespace std;

int solve(int n) {
	if(n == 0) return 1;
	if(n < 0) return 0;
	return solve(n-1) + solve(n-2) + solve(n-3);
}

// using memoization
int solveDP(int n, int *dp){
	if(n == 0) return 1;
	if(n < 0) return 0;
	dp[n] = solveDP(n-1, dp) + solveDP(n-2, dp) + solveDP(n-3, dp);
	return dp[n];
}

// Bottom up dp
// O( nk )
int bootonUpWays(int n, int k) {
	int *dp = new int[n];
	sp[0] = 1;
	for(int step = 1; step <= n; step++){
		dp[step] = 0;
		for(int j = 1; j <= k; j++){
			if(step - j >= 0)
				dp[step] += dp[step-j]
		}
	}
	return dp[n];
}

int main() {
	int n = 4;
	cout << solve(n) << '\n';

	//dp array
	int *dp = new int[n];
	fill(dp, dp+n, -1);
	cout << solveDP(n, dp) << '\n';

	delete[] dp;
	return 0;
}