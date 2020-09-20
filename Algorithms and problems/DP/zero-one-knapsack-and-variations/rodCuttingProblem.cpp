#include<bits/stdc++.h>
using namespace std;


int cut(vector<int> prices, int n) {
	if(n <= 0) return 0;

	int max_profit = INT_MIN;
	for(int i = 0; i < n; i++) {
		max_profit = max(max_profit, prices[i] + cut(prices, n - i - 1));
	}
	return max_profit;
}

int memoize(vector<int> prices, int n, vector<int>& dp) {
	if(n <= 0) return 0;

	if(dp[n] != -1) return dp[n];
	int max_profit = INT_MIN;
	for(int i = 0; i < n; i++) {
		max_profit = max(max_profit, prices[i] + cut(prices, n - i - 1));
	}
	return dp[n] = max_profit;
}

int main() {
	int n = 8; // size of the rod
	vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << cut(prices, n) << endl;

	// memoize solution
	vector<int> dp(n+1, -1);
	cout << memoize(prices, n, dp) << endl;
	return 0;
}
