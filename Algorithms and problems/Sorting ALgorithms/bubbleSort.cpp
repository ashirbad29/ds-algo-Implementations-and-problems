#include <bits/stdc++.h>
using namespace std;

// Logic for Bubble Sort
// Time Complexity is O(n*n) in all cases
void bubbleSort(vector<int>& array){
	// if the arrrya size is one we need't to sort it
	if(array.size() == 1) return;

	for(int i = 0; i < array.size() -1; i++){
		for(int j = 0; j < array.size() - i -1; j++){
			if(array[j] > array[j+1]) swap(array[j], array[j+1]);
		}
	}
}

// optimized bubble sort
// Time Complexity is O(N) if array is already sorted in best case
void optimizedBubbleSort(vector<int>& array) {
	if(array.size() == 1) return;

	bool isSwapped;
	for(int i = 0; i < array.size() -1; i++){
		isSwapped = false;
		for(int j = 0; j < array.size() -i -1; j++){
			if(array[j] > array[j+1]) {
				swap(array[j], array[j+1]);
				isSwapped = true;
			}
		}
		if(isSwapped = false) // array is already sorted
			break;
	}
}

int main()
{	
	int N;    
	cin >> N;

	vector<int> array(N);
	for(int &x: array) cin >> x;

	optimizedBubbleSort(array);
	for(int x: array) cout << x << " ";
	cout << endl;

	return 0;
}