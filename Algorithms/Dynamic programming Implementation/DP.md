# Dynamic programming Implementation

Dynamic programming is a powerful algorithmic technique used to solve problems by breaking them down into smaller subproblems and reusing solutions to those subproblems. This technique is especially useful for problems with overlapping subproblems, where the same subproblem is solved multiple times. Here is an implementation of dynamic programming using C, with examples.

## Example 1: Fibonacci Series

The Fibonacci sequence is a classic example of dynamic programming. The sequence starts with 0 and 1, and each subsequent number is the sum of the two preceding ones. Here is an implementation of the Fibonacci sequence using dynamic programming:

```
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
    int n = 10;
    printf("The %dth number in the Fibonacci sequence is %d", n, fibonacci(n));
    return 0;
}
```

In this implementation, we create an array called memo that stores the results of previous calculations. We start by initializing memo[0] and memo[1] to the first two numbers in the sequence. Then we loop through the remaining numbers and calculate each one by adding the two preceding numbers together. Finally, we return the nth number in the sequence.

## Example 2: Coin Change
The coin change problem is a classic example of dynamic programming. The problem is to find the minimum number of coins needed to make a given amount of change, using a given set of coin denominations. Here is an implementation of the coin change problem using dynamic programming:

```
#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount) {
    int memo[amount+1];
    memo[0] = 0;
    for (int i = 1; i <= amount; i++) {
        memo[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = memo[i-coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < memo[i]) {
                    memo[i] = sub_res + 1;
                }
            }
        }
    }
    return memo[amount];
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 43;
    printf("Minimum number of coins required to make %d cents is %d\n", amount, minCoins(coins, n, amount));
    return 0;
}

```
In this implementation, we create an array called memo that stores the minimum number of coins needed to make each amount of change. We start by initializing memo[0] to 0, since no coins are needed to make 0 cents. Then we loop through the remaining amounts and calculate the minimum number of coins needed for each one by iterating through the coin denominations and checking if each coin can be used to make the current amount of change. If so, we subtract the coin value from the current amount and look up the minimum number of coins needed to make the remaining amount in memo. We update memo[i] if the new minimum is smaller than the current value. Finally, we return memo[amount], which contains the minimum number of coins needed to make the given amount of change.