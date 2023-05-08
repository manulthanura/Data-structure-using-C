# Greedy Implementation

Greedy algorithms are a class of algorithms that make locally optimal choices at each step, with the hope of finding a global optimum. Here is an implementation of greedy algorithms using C, with examples.

## Example 1: Fractional Knapsack
The fractional knapsack problem is a classic example of a greedy algorithm. The problem is to fill a knapsack with a given capacity with items of different weights and values, such that the total value of the items in the knapsack is maximized. Here is an implementation of the fractional knapsack problem using a greedy algorithm:

```
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double density;
} Item;

int cmp(const void* a, const void* b) {
    Item* ia = (Item*)a;
    Item* ib = (Item*)b;
    return (int)(ib->density - ia->density);
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    double result = 0.0;
    qsort(items, n, sizeof(Item), cmp);
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            result += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            result += items[i].density * capacity;
            break;
        }
    }
    return result;
}

int main() {
    int capacity = 50;
    Item items[] = {{10, 60, 0.6}, {20, 100, 0.5}, {30, 120, 0.4}};
    int n = sizeof(items)/sizeof(items[0]);
    printf("Maximum value that can be obtained with a capacity of %d is %.2f\n", capacity, fractionalKnapsack(capacity, items, n));
    return 0;
}

```

In this implementation, we first calculate the density of each item by dividing its value by its weight. Then we sort the items in descending order of density, so that we choose the most valuable items first. We loop through the sorted items and add them to the knapsack until it is full. If an item cannot fit completely into the knapsack, we add a fraction of it proportional to the remaining capacity. Finally, we return the total value of the items in the knapsack.