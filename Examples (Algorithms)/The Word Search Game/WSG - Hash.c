#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include<time.h>
#define MAX_WORD_LENGTH 100
#define HASH_TABLE_SIZE 1000003

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

unsigned long hash(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // djb2 hash function
    }

    return hash % HASH_TABLE_SIZE;
}

void insertWord(const char* word) {
    unsigned long index = hash(word);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int checkWordInDatabase(const char* word) {
    unsigned long index = hash(word);

    if (hashTable[index] == NULL) {
        return 0; // Word not found in the database
    }

    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found in the database
        }
        current = current->next;
    }

    return 0; // Word not found in the database
}

void freeHashTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void initializeHashTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int main() {
    initializeHashTable();

    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Unable to open the database file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH * 2]; // Twice the max word length to account for commas
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            insertWord(token);
            token = strtok(NULL, ",");
        }
    }

    fclose(file);

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check in the database: ");
    scanf("%s", word);

    // time para
    clock_t start, end;
    double execution_time;
    start = clock(); // time starts

    if (checkWordInDatabase(word)) {
        printf("The word '%s' is in the database.\n", word);
    } else {
        printf("The word '%s' is not in the database.\n", word);
    }

    end = clock(); // time ends
    /* Get the time taken by program to execute in seconds */
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds : %f", duration); // print time

    freeHashTable();

    // Prompt the user to press a key before exiting
    getchar();

    return 0;
}
