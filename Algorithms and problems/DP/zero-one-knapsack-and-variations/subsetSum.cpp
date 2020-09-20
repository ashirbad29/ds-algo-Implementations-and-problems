#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Recursive solution
bool subsetSumR(vector<int> arr, int sum, int n){
	// base case
	if(n == 0 && sum == 0) return true;
	else if(n == 0 && sum != 0) return false;
	else if(sum == 0 && n != 0) return true;

	if(arr[n-1] <= sum){
		return subsetSumR(arr, sum - arr[n-1], n-1) || subsetSumR(arr, sum, n-1);
	}
	else return subsetSumR(arr, sum, n-1);
}

bool bottomUpDp(vector<int> arr, int sum, int n){
	bool dp[n+1][sum+1];

	// if sum is 0 answer is true
	for(int i = 0; i <= n; i++)
		dp[i][0] = true;

	// if sum is not zero ans set is empty then ans is false
	for(int i = 1; i <= sum; i++)
		dp[0][i] = false;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}

int main() {
	// given a array and a interger find if therere is a subset exists in arr
	// whose sum of elements in equal to the given integer

	vector<int> arr = {2, 12, 6, 1, 5};
	int sum = 8;
	int n = arr.size();

	cout << subsetSumR(arr, sum, n) << endl;

	cout << bottomUpDp(arr, sum, n) << endl;
	return 0;
}