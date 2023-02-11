/* Array Data Structure implementation
Date created: Saturday; February 01, 2023 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int n = 0;

void add(int value) {
  if (n < MAX_SIZE) {
    array[n++] = value;
    printf("Value added successfully!\n");
  } else {
    printf("Array is full. Cannot add more values.\n");
  }
}

void update(int index, int value) {
  if (index >= 0 && index < n) {
    array[index] = value;
    printf("Value updated successfully!\n");
  } else {
    printf("Invalid index. Cannot update value.\n");
  }
}

void delete(int index) {
  if (index >= 0 && index < n) {
    for (int i = index; i < n - 1; i++) {
      array[i] = array[i + 1];
    }
    n--;
    printf("Value deleted successfully!\n");
  } else {
    printf("Invalid index. Cannot delete value.\n");
  }
}

int main() {
  add(1);
  add(2);
  add(3);
  update(1, 4);
  delete(0);
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}

// This implementation uses a fixed-size array of size MAX_SIZE to store the values, and the n variable to keep track of the number of elements currently stored in the array. The add function adds a new value to the end of the array, the update function updates the value at a specific index, and the delete function removes the value at a specific index.