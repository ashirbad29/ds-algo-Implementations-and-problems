#include <iostream>
#include <algorithm>

using namespace std;

void heapify(int arr[], int n, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int greatest = i;

	if (left < n && arr[greatest] < arr[left]) {
		greatest = left;
	}

	if (right < n && arr[greatest] < arr[right]) 
		greatest = right;
	
	if(i != greatest) {
		swap(arr[i], arr[greatest]);
		heapify(arr, n, greatest);
	}

}

void heapSort(int arr[], int n) {
	// rearrange the array to form a heap
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(arr, n, i);

	// one by one sort the heap by swaping max with min value
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);

		// call heapify for the reduces array till ith element
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {13, 4, 5, 20, 23};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	printArray(arr, n);

	return 0;
}
