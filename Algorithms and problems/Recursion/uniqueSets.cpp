#include <iostream>
#include <string>
#include <set>
using namespace std;

void solve(string input, string output, set<string> &s){
	if(input.length() == 0){

		s.insert(output);
		return;
	}

	string op1 = output;
	string op2 = output;

	op2.push_back(input[0]);
	input.erase(0, 1); // shorting the input

	solve(input, op1, s);
	solve(input, op2, s);
	return;
}

int main() {
	string input = "aab";
	string output = "";

	set<string> s;
	solve(input, output, s);

	// set contins unique subsets
	for(auto x: s) cout << x << " ";
	cout << endl;

	return 0;
}