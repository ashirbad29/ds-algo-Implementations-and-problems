#include <iostream>
#include <vector>
using namespace std;

// Naive Appoarch
bool isPrime(int n) {
	if(n == 1) return false;
	if(n == 2) return true;

	for(int i = 3; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

// seive appoarch - Genereate a array containing prime numbers
// complexity is O (n log (log n)) // nearly linear
void prime_seive(vector<bool> &is_prime, int n){
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i <= n; i++) {
		// check if i is marked o not
		if(is_prime[i] && (long long)i * i <= n){
			// mark all its multiple as not prime
			for(int j = i * i; j <= n; j+=i)
				is_prime[j] = false;
		}
	}
}

int main() {
	int n = 100;

	vector<bool> is_prime(n+1, true);
	prime_seive(is_prime, n);

	for(int i = 2; i < is_prime.size(); i++) {
		if(is_prime[i]) cout << i << ' ';
		else continue;
	}

	return 0;
}