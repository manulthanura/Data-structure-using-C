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
  int decision, value, index;
  while (1) {
    printf("1. Add\n");
    printf("2. Update\n");
    printf("3. Delete\n");
    printf("4. Exit\n");
    printf("Enter your decision: ");
    scanf("%d", &decision);
    switch (decision) {
      case 1:
        printf("Enter the value to be added: ");
        scanf("%d", &value);
        add(value);
        break;
      case 2:
        printf("Enter the index of the value to be updated: ");
        scanf("%d", &index);
        printf("Enter the new value: ");
        scanf("%d", &value);
        update(index, value);
        break;
      case 3:
        printf("Enter the index of the value to be deleted: ");
        scanf("%d", &index);
        delete(index);
        break;
      case 4:
        for (int i = 0; i < n; i++) {
          printf("%d ", array[i]);
        }
        printf("\n");
        exit(0);
      default:
        printf("Invalid decision. Please enter a valid option.\n");
        break;
    }
  }
  return 0;
}


// This implementation uses a fixed-size array of size MAX_SIZE to store the values, and the n variable to keep track of the number of elements currently stored in the array. The add function adds a new value to the end of the array, the update function updates the value at a specific index, and the delete function removes the value at a specific index.