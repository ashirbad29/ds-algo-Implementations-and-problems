/* Prime Seive */
#include <iostream>
#include <vector>
using namespace std;

vector<bool> seiveOfErtoSthenes(int n){
	vector<bool> primes(n+1);
	// assuming all numbers are prime
	fill(primes.begin(), primes.end(), true);

	primes[0] = primes[1] = false;
	for(int i = 2; i * i <= n; i++) {
		// marking multiples of i as false
		for (int j = 2 * i; j <= n; j += i){
			primes[j] = false;
		}
	}
	return primes;
}

int main() {
	vector<bool> primeNums = seiveOfErtoSthenes(19);
	for(int i = 0; i < primeNums.size(); i++){
		if(primeNums[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}