#include <iostream>
using namespace std;

int fib(int n) {
   return (n == 0 || n == 1) ?  n : fib(n-1) + fib(n-2);
}

int fibWithDp(int n, int DP[]) {
    if(n == 0 || n == 1) {
        DP[n] = n;
        return n;
    }

    // if n is already computed
    if(DP[n] != -1) return DP[n];
    else {
        // if n is not computed
        // compute and store it in DP
        DP[n] = fibWithDp(n-1, DP) + fibWithDp(n-2, DP);
        return DP[n];
    }
}
int bottomUpFib(int n) {
    int *dp = new int[n];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fibOpt(int n) {
    // initial values
    int a = 0, b = 1;
    int c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {


cout << fib(5) << endl;

int DP[101];
fill(DP, DP+100, -1);
cout << fibWithDp(5, DP) << endl;
cout << bottomUpFib(5) << endl;
cout << fibOpt(5) << endl;
return 0;

}
