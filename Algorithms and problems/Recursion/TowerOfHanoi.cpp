#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(int source, int dest, int helper, int n){
	if(n == 1){
		cout << "move disk no " << n << " from " << source << " to " << dest << '\n';
		return;
	}

	solve(source, helper, dest, n-1);

	cout << "move disk no " << n << " from " << source << " to " << dest <<'\n';

	solve(helper, dest, source, n-1);
	return;
}

int main() {
	/* Tower of Hanoi*/
	int n = 3; // no of disks
	int source = 1;
	int helper = 2;
	int dest = 3;

	solve(source, dest, helper, n);
	return 0;
}