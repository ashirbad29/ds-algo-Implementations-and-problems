#include <iostream>
#include <climits>
using namespace std;

// recursive solution
// works for smaller inputs
int coinsNeeded(int *coins, int amount, int n) {
	if(amount == 0) return 0;
	int ans = INT_MAX;

	// check for all possible coins
	for (int i = 0; i < n; i++) {
		if(amount - coins[i] >= 0){
			int smallAns = coinsNeeded(coins, amount-coins[i], n);
			if(smallAns != INT_MAX)
				ans = min(ans, smallAns+1);
		}
	}
	return ans;
}

int coinsNeededDP(int *coins, int amount, int n) {
	int *dp = new int[amount+1];
	dp[0] = 0;
	// initialize the dp array
	for(int i = 1; i <= amount; i++) {
		dp[i] = INT_MAX;
	}

	for(int rupay = 1; rupay <= amount; ++rupay){
		for(int i = 0; i < n; i++) {
			if(coin[i] <= rupay){
				int smallerAns = dp[rupay-coins[i]];
				if(smallAns != INT_MAX) dp[rupay] = min(dp[rupay], smallAns + 1);
			}
		}
	}
	return dp[amount];
}

int main() {
 	int coins[] = {1, 7, 10};
 	int n = 3;
 	int amount = 16;
 	cout << coinsNeeded(coins, amount, n) << endl;
	return 0;
}