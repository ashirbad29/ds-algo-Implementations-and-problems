#include <iostream>
using namespace std;

// prime factorization is finding which prime numbers
// multiply together to form the original number
void print_prime_factors(int N) {
	for(int i = 2; i * i <= N; i++) {
		if(N % i == 0) 
			cout << i << " ";
		while(N % i == 0)
			N /= i;
	}
	if(N > 1)
		cout << N << endl;
}

int main() {
	int N = 207;
	print_prime_factors(N);
	return 0;
}