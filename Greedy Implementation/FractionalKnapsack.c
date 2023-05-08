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
