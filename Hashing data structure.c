#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define HASH_TABLE_SIZE 10

struct Node {
  int key;
  int value;
  struct Node *next;
};

struct Node *hash_table[HASH_TABLE_SIZE];

int hash(int key) {
  return key % HASH_TABLE_SIZE;
}

void add(int key, int value) {
  int index = hash(key);
  struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
  new_node->key = key;
  new_node->value = value;
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

void update(int key, int value) {
  int index = hash(key);
  struct Node *temp = hash_table[index];
  while (temp != NULL) {
    if (temp->key == key) {
      temp->value = value;
      break;
    }
    temp = temp->next;
  }
}

void delete(int key) {
  int index = hash(key);
  struct Node *temp = hash_table[index];
  if (temp != NULL && temp->key == key) {
    hash_table[index] = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->next != NULL) {
    if (temp->next->key == key) {
      struct Node *to_be_deleted = temp->next;
      temp->next = to_be_deleted->next;
      free(to_be_deleted);
      break;
    }
    temp = temp->next;
  }
}

int main() {
  int decision, key, value;
  while (1) {
    printf("1. Add\n");
    printf("2. Update\n");
    printf("3. Delete\n");
    printf("4. Exit\n");
    printf("Enter your decision: ");
    scanf("%d", &decision);
    switch (decision) {
      case 1:
        printf("Enter the key: ");
        scanf("%d", &key);
        printf("Enter the value: ");
        scanf("%d", &value);
        add(key, value);
        break;
      case 2:
        printf("Enter the key: ");
        scanf("%d", &key);
        printf("Enter the new value: ");
        scanf("%d", &value);
        update(key, value);
        break;
      case 3:
        printf("Enter the key: ");
        scanf("%d", &key);
        delete(key);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid decision. Please enter a valid option.\n");
        break;
    }
  }
  return 0;
}
