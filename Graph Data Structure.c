/* Graph Data Structure implementation
Date created: Saturday; June 19, 2023.

In this code, the user is prompted to make a decision on what operation to perform (add, update, delete, print or exit), and the appropriate function is called based on the decision. The program will keep prompting the user for a decision until they choose to exit the program.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_VERTICES];
};

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int i;
    for (i = 0; i < MAX_VERTICES; i++)
        graph->adjList[i] = NULL;
    return graph;
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < MAX_VERTICES; v++) {
        struct Node* temp = graph->adjList[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void updateEdge(struct Graph* graph, int src, int dest) {
    struct Node* temp = graph->adjList[src];
    while (temp) {
        if (temp->vertex == dest) {
            printf("Enter new value for the edge between %d and %d: ", src, dest);
            int newDest;
            scanf("%d", &newDest);
            temp->vertex = newDest;
            printf("Edge updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Edge between %d and %d does not exist.\n", src, dest);
}

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* temp = graph->adjList[src];
    struct Node* prev = NULL;

    while (temp) {
        if (temp->vertex == dest) {
            if (prev == NULL)
                graph->adjList[src] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Edge deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Edge between %d and %d does not exist.\n", src, dest);
}

int main() {
    struct Graph* graph = createGraph();
    int src, dest;
    char decision;

    do {
        printf("\nGraph Operations:\n");
        printf("1. Add an edge\n");
        printf("2. Update an edge\n");
        printf("3. Delete an edge\n");
        printf("4. Print the graph\n");
        printf("5. Exit\n");
        printf("Enter your decision: ");
        scanf(" %c", &decision);

        switch (decision) {
            case '1':
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case '2':
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                updateEdge(graph, src, dest);
                break;
            case '3':
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                deleteEdge(graph, src, dest);
                break;
            case '4':
                printf("Graph:\n");
                printGraph(graph);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid decision. Please try again.\n");
        }
    } while (decision != '5');

    return 0;
}
