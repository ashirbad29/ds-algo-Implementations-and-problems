#include <iostream>
#include <vector>

using namespace std;

// Naive Recursive approach
int recursiveKnapsack(vector<int> weight, vector<int> value, int w, int n){
	if(n == 0 || w == 0) return 0; // base case

	// check if we can include or not
	if(weight[n-1] <= w){ // we can include or exclude based on the max profit we get
		return max(value[n-1] + recursiveKnapsack(weight, value, w - weight[n-1], n-1),
			recursiveKnapsack(weight, value, w, n-1));
	}
	// if the weight is greate then capacity, we igonore the item
	else return recursiveKnapsack(weight, value, w, n-1);
}

// Memoization dp
int knapsackDP(vector<int> weight, vector<int> value, int w, int n, vector<vector<int>> dp){
	if(n == 0 || w == 0) return 0;

	// remembering the history
	if(dp[n][w] != -1) return dp[n][w];

	// memoization
	if(weight[n-1] <= w){
		return dp[n][w] = max(value[n-1] + knapsackDP(weight, value, w- weight[n-1], n-1, dp),
			knapsackDP(weight, value, w, n-1, dp));
	}
	else return dp[n][w] = knapsackDP(weight, value, w, n-1, dp); 
}

// Botton-up approach
int bottomUp(vector<int> weight, vector<int> value, int w, int n){
	cout << "inside the bottom up function" << '\n';
	// make a matrix of size n * w
	// vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

	int dp[n+1][w+1];

	// Initialization


	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= w; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(weight[i-1] <= w)
				dp[i][j] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}

	// debugging
	for (int i = 0; i <= n; i++){
		for(int j = 0; j <= w; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}

	return dp[n][w];
}
int main() {
	vector<int> weight = {1, 2, 3};
	vector<int> value = {10, 15, 40};
	int w = 6; // weight of the bag (KnapSack)
	int n = weight.size();
	// solution: 220

	// memoization matrix	
	vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
	cout << knapsackDP(weight, value, w, n, dp) << endl;

	cout << recursiveKnapsack(weight, value, w, n) << endl;

	cout << bottomUp(weight, value, w, n) << endl;
	return 0;
}