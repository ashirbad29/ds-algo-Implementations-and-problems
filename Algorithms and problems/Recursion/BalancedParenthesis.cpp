#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generate(int open, int close, string output, vector<string>& storage) {
	if(open == 0 && close == 0) {
		storage.push_back(output); 
		return;
	}
	if(open != 0){
		string op1 = output;
		op1.push_back('(');
		generate(open-1, close, op1, storage);
	}
	if(close > open){
		string op1 = output;
		op1.push_back(')');
		generate(open, close-1, op1, storage);
	}
}

int main() {
	// Generate all balanced parenthesis for n
	int n = 3;

	int open = n;
	int close = n;
	string output = "";
	vector<string> storage;
	generate(open, close, output, storage);

	for(auto x: storage) cout << x << " ";
	cout << endl;
	return 0;
}