/* A simple Tree (dynamic) implementation
Date created: Friday; April 01, 2022 */


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct queue {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->rear == -1;
}

int isFull(Queue *queue) {
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    queue->items[++queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->items[queue->front++];
    if (queue->front > queue->rear) {
        initialize(queue);
    }
    return item;
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("%d dequeued from queue\n", dequeue(&queue));
    printf("%d dequeued from queue\n", dequeue(&queue));
    printf("%d dequeued from queue\n", dequeue(&queue));

    return 0;
}
