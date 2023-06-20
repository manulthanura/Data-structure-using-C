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
