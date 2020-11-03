/* Prime Seive */
#include <iostream>
#include <vector>
using namespace std;

vector<bool> seiveOfErtoSthenes(int N){
	vector<bool> is_prime(N+1, true);
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i * i <= N; i++) {
		if(is_prime[i]) {
			// marking multiples of i as false
			for (int j = i + i; j <= N; j += i)
				is_prime[j] = false;
		}
	}
	return is_prime;
}

int main() {
	vector<bool> primeNums = seiveOfErtoSthenes(19);
	for(int i = 0; i < primeNums.size(); i++){
		if(primeNums[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}