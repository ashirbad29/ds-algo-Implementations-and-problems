#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& array, int start, int mid, int end) {
	int size_1 = mid - start + 1;
	int size_2 = end - mid;

	vector<int> L(size_1);
	vector<int> R(size_2);

	for(int i = 0; i < size_1; i++) L[i] = array[i + start];
	for(int i = 0; i < size_2; i++) R[i] = array[i + mid + 1];

	// merge sorted arrays usign two pointer
	int i = 0, j = 0, k = start;
	while(i < size_1 && j < size_2) {
		if(L[i] < R[j]) 
			array[k++] = L[i++];
		else
			array[k++] = R[j++]; 
	}
	while(i < size_1)  // R exhausted
		array[k++] = L[i++];

	while(j < size_2)  // L exhausted
		array[k++] = R[j++];
}

void merge_sort(vector<int>& array, int start, int end) {
	// base case
	if(start >= end) return;

	// follow 3 steps
	//1. Divide
	int mid = (start + end) / 2;

	// Recursively didvide the array untill they are sorted (i.e when there is only 1 element)
	merge_sort(array, start, mid);
	merge_sort(array, mid+1, end);

	// merge the two array
	merge(array, start, mid, end);
}

int main() {
	int n;
	cin >> n;

	vector<int> array(n);
	for(int& x: array) cin >> x;

	merge_sort(array, 0, n-1);

	for(int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}