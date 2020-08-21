#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void insert(vector<int>& v, int temp){
	if(v.size() == 0 || v[v.size() - 1] <= temp){
		v.push_back(temp);
		return;
	}
	int val = v[v.size()-1];
	v.pop_back();
	insert(v, temp);
	v.push_back(val);
	return;
}

void sortx(vector<int>& v){
	if(v.size() == 1) return;

	int temp = v[v.size() - 1];
	v.pop_back();
	sortx(v);
	insert(v, temp);
}

int main() {
	vector<int> v = {4, 3, 6, 8, 1};
	sortx(v);

	for(int x: v) cout << x << " ";
	cout << '\n';
	return 0;
}