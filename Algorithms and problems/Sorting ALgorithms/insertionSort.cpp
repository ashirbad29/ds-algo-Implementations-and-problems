#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& array) {
	int i, key, j;
	for(i = 1; i < array.size(); i++) {
		key = array[i];
		j = i-1;
		while(j >= 0 && key < array[j]) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

int main() {
	vector<int> array = {3, 5, 1, 4, 15, 12, 9, -1};
	insertion_sort(array);
	for(int x: array)
		cout << x << " ";
	cout << "\n";
	return 0;
}