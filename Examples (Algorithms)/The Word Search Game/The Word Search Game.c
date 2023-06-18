#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100

typedef struct Word {
    char* word;
    struct Word* next;
} Word;

typedef struct {
    Word* hash_table[HASH_SIZE];
} WordSearchEngine;

// Function to calculate the hash value for a given word
unsigned int calculateHash(const char* word) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += (unsigned int)word[i];
    }
    return hash % HASH_SIZE;
}

// Function to search for a word in the WordSearchEngine
int searchWord(WordSearchEngine* engine, const char* word) {
    unsigned int hash = calculateHash(word);
    Word* current = engine->hash_table[hash];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;  // Word found
        }
        current = current->next;
    }
    return 0;  // Word not found
}

// Function to add a new word to the WordSearchEngine
void addWord(WordSearchEngine* engine, const char* word) {
    unsigned int hash = calculateHash(word);
    Word* newWord = (Word*)malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    // Insert the new word at the beginning of the hash bucket
    if (engine->hash_table[hash] == NULL) {
        engine->hash_table[hash] = newWord;
    } else {
        Word* current = engine->hash_table[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newWord;
    }
}

// Function to delete a word from the WordSearchEngine
void deleteWord(WordSearchEngine* engine, const char* word) {
    unsigned int hash = calculateHash(word);
    Word* current = engine->hash_table[hash];
    Word* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            if (previous == NULL) {
                engine->hash_table[hash] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->word);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to edit a word in the WordSearchEngine
void editWord(WordSearchEngine* engine, const char* oldWord, const char* newWord) {
    unsigned int hash = calculateHash(oldWord);
    Word* current = engine->hash_table[hash];
    while (current != NULL) {
        if (strcmp(current->word, oldWord) == 0) {
            free(current->word);
            current->word = strdup(newWord);
            return;
        }
        current = current->next;
    }
}

int main() {
    WordSearchEngine engine;

    // Initialize the hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        engine.hash_table[i] = NULL;
    }

    // Add some initial words
    addWord(&engine, "apple");
    addWord(&engine, "banana");
    addWord(&engine, "cat");
    addWord(&engine, "dog");

    // Search for a word
    char searchInput[100];
    printf("Enter a word to search: ");
    scanf("%s", searchInput);
    if (searchWord(&engine, searchInput)) {
        printf("The word is in the database.\n");

        // Ask user to perform add, edit, or delete operations
        int choice;
        printf("What would you like to do?\n");
        printf("1. Add a new word\n");
        printf("2. Edit the word\n");
        printf("3. Delete the word\n");
        printf("Enter your choice (1-3) or enter any to exit: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1: {
                char addInput[100];
                printf("Enter a new word to add: ");
                fgets(addInput, sizeof(addInput), stdin);
                addInput[strcspn(addInput, "\n")] = '\0';  // Remove trailing newline character
                addWord(&engine, addInput);
                printf("New word added successfully.\n");
                break;
            }
            case 2: {
                char editInput[100], editedWord[100];
                printf("Enter the word to edit: ");
                fgets(editInput, sizeof(editInput), stdin);
                editInput[strcspn(editInput, "\n")] = '\0';  // Remove trailing newline character
                printf("Enter the edited word: ");
                fgets(editedWord, sizeof(editedWord), stdin);
                editedWord[strcspn(editedWord, "\n")] = '\0';  // Remove trailing newline character
                editWord(&engine, editInput, editedWord);
                printf("Word edited successfully.\n");
                break;
            }
            case 3: {
                char deleteInput[100];
                printf("Enter the word to delete: ");
                fgets(deleteInput, sizeof(deleteInput), stdin);
                deleteInput[strcspn(deleteInput, "\n")] = '\0';  // Remove trailing newline character
                deleteWord(&engine, deleteInput);
                printf("Word deleted successfully.\n");
                break;
            }
            default:
                printf("exit\n");
                break;
        }
    } else {
        printf("The word is not in the database.\n");
    }

    return 0;
}
