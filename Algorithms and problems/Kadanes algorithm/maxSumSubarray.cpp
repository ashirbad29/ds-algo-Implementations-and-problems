#include <bits/stdc++.h>
using namespace std;


// kadane's algorithm for maximum contigeous subarray problem 
int kadanasAlgo(vector<int> arr) {
	int maxSum = INT_MIN;
	int sum = 0;

	for(int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		if(sum > maxSum) maxSum = sum;

		// The main idea of kadane's algo is to look for all +ve subarrays
		// and keep track of the maximum sum
		// if a subarray has -ve sum we discard it
		if(sum < 0) sum = 0;
	}
	return maxSum;
}

int main() {
	vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4}
	cout << kadanasAlgo(arr) << endl;
	return 0;
}

/*
	Link to the problem  - https://leetcode.com/problems/maximum-subarray/
	Link to GFG documentation - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
	Video Explaination - https://www.youtube.com/watch?v=w_KEocd__20
*/
