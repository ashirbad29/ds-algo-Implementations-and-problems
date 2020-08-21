#include <iostream>
#include <vector>
#include <string>
using namespace std;
	
void solve(string input, string output){
	if(input.length() == 0) {
		cout << output << " | ";
		return;
	}

	string op1 = output;
	string op2 = output;

	// incldue first char
	op1.push_back(input[0]);
	op2.push_back(' ');
	op2.push_back(input[0]);
	input.erase(0, 1);

	solve(input, op1);
	solve(input, op2);
}

int main() {
	string str = "abc";
	string output;
	output.push_back(str[0]);
	str.erase(0, 1);
	solve(str, output);
	return 0;	
}