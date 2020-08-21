#include <iostream>
#include <string>

using namespace std;

void solve(string input, string output) {
	if(input.length() == 0) {
		cout << output << " ";
		return;
	}

	string op1 = output;
	string op2 = output;

	// choice #1 samll letter
	op1.push_back(input[0]);
	
	// choice #2 capital letter
	op2.push_back(toupper(input[0]));
	input.erase(0, 1);

	solve(input, op1);
	solve(input, op2);
	return;
}

int main() {
	string input = "ab";
	string output = " ";
	solve(input, output);
	return 0;
}