#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class HashTable{
private:
	list<int> *table;
	int total_elements;

	// Hash function
	int hash(int key) {
		return key % total_elements;
	}
public:
	// constructor to create hash table with n size
	HashTable(int n) {
		total_elements = n;
		table = new list <int>[total_elements];
	}
	~HashTable() {
		cout << "destructor called" << endl;
		delete[] table;
	}
	void insertElement(int key) {
		table[hash(key)].push_back(key);
	}

	void removeElement(int key) {
		int x = hash(key);

		list<int>::iterator i;
		for (i = table[x].begin(); i != table[x].end(); ++i) {
			// check if the terator pointd to correct location
			if (*i == key) break;
		}

		//if the item was found in list then delete it
		if (i != table[x].end()) table[x].erase(i);
	}

	void printAll () {
		// Traverse each index
		for (int i = 0; i < total_elements; i++) {
			cout << "index " << i << ": ";
			// Traverse the list at current index
			for (int j: table[i]) 
				cout << j << " => ";
			cout << endl;
		}
	}
};

int main () {
	// Create a hash table
	HashTable ht(3);

	int arr[] = {2, 4, 6, 8, 10};

	for (int i = 0; i < 5; i++) {
		ht.insertElement(arr[i]);
	}

	ht.printAll();
	return 0;
}