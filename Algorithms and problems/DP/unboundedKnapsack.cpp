#include <bits/stdc++.h>
using namespace std;

// naive recursive approach
int recursive(vector<int> v, vector<int> wt, int w, int n) {
	if(w == 0 || n == 0) return 0;

	if(wt[n-1] <= w) {
		// since multiple occurance is possibel
		// we can add it later also
		int add_item = v[n-1] + recursive(v, wt, w - wt[n-1], n);
		int skip_item = recursive(v, wt, w, n-1);
		return max(add_item, skip_item);
	} else {
		return recursive(v, wt, w, n-1);
	}
}

// top down dp approach (memoization)
int topDown(vector<int> v, vector<int> wt, int w, int n, vector<int>& dp) {
	if(w == 0 || n == 0) return 0;
	if(dp[w] != -1) return dp[w];

	if(wt[n-1] <= w) {
		int add_item = v[n-1] + topDown(v, wt, w - wt[n-1], n, dp);
		int skip_item = topDown(v, wt, w, n-1, dp);
		return  dp[w] = max(add_item, skip_item);
	} else {
		return dp[w] = topDown(v, wt, w, n-1, dp);
	}
}

// iterative bottom up approach
int bottomUp (vector<int> v, vector<int> wt, int w, int n) {
	vector<int> dp(w+1, 0);

	for(int i = 0; i <= w; i++) {
		for(int j = 0; j < n; j++)
			if(wt[j] <= i)
				dp[i] = max(v[j] + dp[i - wt[j]], dp[i]);
	}
	return dp[w]; 
}

int main() {
	/*	
		unbounded kanpsack:
		multiple occurances of same item in knapsack
		is allowed
	*/

	int w = 3; // capacity of knapsack
	int n = 3;   // no of items
	vector<int> value = {1, 2, 3};
	vector<int> weight = {1, 3, 4};

	cout << recursive(value, weight, w, n) << endl; // 100

	// top down
	// in unbounded knapsack n does't matter
	// we can add a element many times
	// so we only require a single dimesnsional dp array to store
	vector<int> dp(w+1, -1);
	cout << topDown(value, weight, w, n, dp) << endl;  

	// bottom up
	cout << bottomUp(value, weight, w, n) << endl;
	return 0;
}