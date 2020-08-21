#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generate(int input, int one, int zero, string output) {
	if(input == 0) {
		cout << output << " ";
		return;
	}

	// we can print one no matter what
	string op1 = output;
	op1.push_back('1');
	generate(input-1, one+1, zero, op1);

	// Condition for zero j
	if(one > zero) {
		string op1 = output;
		op1.push_back('0');
		generate(input-1, one, zero+1, op1);
	}
}

void solve(int n){
	int one = 0;
	int zero = 0;

	string output = "";
	generate(n, one, zero, output);
}

int main() {
	int n = 3;
	string output;
	solve(n);
	return 0;
}