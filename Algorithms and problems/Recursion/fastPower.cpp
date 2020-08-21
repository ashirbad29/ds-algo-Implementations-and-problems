#include <iostream>
using namespace std;

int fastPower(int a, int b) {
	int res = 1;
	while (b > 0) {
		if ( (b&1) != 0 ) {
			res = res*a;
		}

		a = a * a;
		b = b >> 1;
	}
	return res;
}

int main() {
	cout << fastPower(3, 5) << endl;
	return 0;
}

/*
	Properties of modular arithmatic
	(a + b) % n = ( a%n + b%n ) % n
*/