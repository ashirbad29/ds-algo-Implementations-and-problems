#include <iostream>
#define lli long long int
using namespace std;

int print_factors_count(lli N) {
  int count = 0;
  // factors always come in pairs
  // except for perceft square, both factors are equal
  for(int i = 1; i * i <= N; i++)
    if(N % i == 0) {
      count++;
      if(i != N/i)
        count++;
    }

    return count;
}

int main() {
	int N = 36;
	cout << print_factors_count(N) << endl;
  return 0;
}