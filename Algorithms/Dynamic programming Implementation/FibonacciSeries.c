/* The Fibonacci sequence is a classic example of dynamic programming. The sequence starts with 0 and 1, and each subsequent number is the sum of the two preceding ones. */

#include <stdio.h>

int fibonacci(int n) {
    int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("The %dth number in the Fibonacci sequence is %d", n, fibonacci(n));
    return 0;
}
