#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
	// to store heap elements
	vector <int> A;

	int PARENT(int i) {
		return (i - 1) / 2;
	}
	int LEFT(int i) {
		return (2 * i + 1);
	}
	int RIGHT(int i) {
		return (2 * i + 2);
	}
	void heapify_down(int i) {
		int left = LEFT(i);
		int right = RIGHT(i);

		// compare a[i] with its left and right child
		// and find the largest
		int largest = i;
		if(left < size() && A[left] > A[i])
			largest = left;
		if(right < size() && A[right] > A[largest])
			largest = right;

		// swap with child having greater value
		if(largest != i) {
			swap(A[i], A[largest]);
			heapify_down(largest);
		}
	}

	void heapify_up(int i) {
		if(i && A[PARENT(i)] < A[i]) {
			swap(A[i], A[PARENT(i)]);

			heapify_up(PARENT(i));
		}
	}

public:
	int size() {
		return A.size();
	}
	bool isEmpty() {
		return size() == 0;
	}

	void push(int key) {
		A.push_back(key);

		int index = size() - 1;
		heapify_up(index);
	}

	int top() {
		if (size() == 0) {
			cout << "Empty" << endl;
			return -1;
		}
		return A[0];
	}
};

int main() {
	MaxHeap mh;

	mh.push(3);
	mh.push(2);
	mh.push(15);

	cout << mh.size() << endl;
	cout << mh.top() << endl;
	return 0;
}