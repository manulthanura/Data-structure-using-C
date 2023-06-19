/* 
Heap Data Structure implementation
Date created: Monday; June 19, 2023

In this code, you can perform operations on a heap data structure, including inserting elements, deleting elements, and printing the heap. The program will keep prompting the user for a decision until they choose to exit.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct Heap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

struct Heap* createHeap() {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(struct Heap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert any more elements.\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = value;

    while (i != 0 && heap->arr[i] < heap->arr[(i - 1) / 2]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Element inserted successfully!\n");
}

void heapify(struct Heap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

void deleteElement(struct Heap* heap, int value) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i] == value)
            break;
    }

    if (i == heap->size) {
        printf("Element %d not found in the heap.\n", value);
        return;
    }

    heap->arr[i] = heap->arr[heap->size - 1];
    heap->size--;

    heapify(heap, i);

    printf("Element deleted successfully!\n");
}

void printHeap(struct Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    int i;
    printf("Heap elements: ");
    for (i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Heap* heap = createHeap();
    int value;
    char decision;

    do {
        printf("\nHeap Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Print the heap\n");
        printf("4. Exit\n");
        printf("Enter your decision: ");
        scanf(" %c", &decision);

        switch (decision) {
            case '1':
                printf("Enter the element to be inserted: ");
                scanf("%d", &value);
                insert(heap, value);
                break;
            case '2':
                printf("Enter the element to be deleted: ");
                scanf("%d", &value);
                deleteElement(heap, value);
                break;
            case '3':
                printHeap(heap);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid decision. Please try again.\n");
        }
    } while (decision != '4');

    return 0;
}
