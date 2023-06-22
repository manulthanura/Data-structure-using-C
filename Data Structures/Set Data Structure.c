#include <stdio.h>
#include <stdlib.h>

struct set_node {
  int value;
  struct set_node *next;
};

struct set {
  struct set_node *head;
};

void set_init(struct set *set) {
  set->head = NULL;
}

void set_insert(struct set *set, int value) {
  struct set_node *new_node = malloc(sizeof(struct set_node));
  new_node->value = value;
  new_node->next = set->head;
  set->head = new_node;
}

void set_update(struct set *set, int value) {
  struct set_node *node = set->head;
  while (node != NULL) {
    if (node->value == value) {
      printf("Enter the new value: ");
      scanf("%d", &value);
      node->value = value;
      break;
    }
    node = node->next;
  }

  if (node == NULL) {
    printf("The value to update does not exist in the set.\n");
  }
}


void set_delete(struct set *set, int value) {
  struct set_node *prev = NULL;
  struct set_node *node = set->head;
  while (node != NULL) {
    if (node->value == value) {
      if (prev == NULL) {
        set->head = node->next;
      } else {
        prev->next = node->next;
      }
      free(node);
      break;
    }
    prev = node;
    node = node->next;
  }
}

void print_set(struct set *set) {
  struct set_node *node = set->head;
  printf("The set is: ");
  while (node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

int main() {
  struct set set;
  set_init(&set);

  int choice;
  while (1) {
    printf("1. Insert\n2. Update\n3. Delete\n4. Print\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        int value;
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        set_insert(&set, value);
        break;
      }
      case 2: {
        int value;
        printf("Enter the value to update: ");
        scanf("%d", &value);
        set_update(&set, value);
        break;
      }
      case 3: {
        int value;
        printf("Enter the value to delete: ");
        scanf("%d", &value);
        set_delete(&set, value);
        break;
      }
      case 4: {
        print_set(&set);
        break;
      }
      case 5: {
        printf("Exiting...\n");
        exit(0);
      }
      default: {
        printf("Invalid choice.\n");
        break;
      }
    }
  }

  return 0;
}
