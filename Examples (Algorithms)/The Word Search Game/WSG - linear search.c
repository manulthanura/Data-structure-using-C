// The algorithm I provided uses a simple linear search approach to check whether a word is present in the text file acting as a database.
// It reads each line of the file and tokenizes it based on commas, then compares each token (word) with the target word.
// In terms of data structures, the algorithm does not use any specific data structure beyond basic C arrays and strings.
// The char line[MAX_WORD_LENGTH * 2] array is used to store a line read from the file, and the char* token pointer is used to hold each word token extracted using strtok().
// The algorithm does not utilize any advanced data structures like hash tables or binary search trees, which could provide faster search times for larger databases.
// Since the algorithm performs a linear search, the time complexity is O(n), where n is the total number of words in the text file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include<time.h>
#define MAX_WORD_LENGTH 100

int checkWordInDatabase(const char* word, const char* databaseFile) {
    FILE* file = fopen(databaseFile, "r");
    if (file == NULL) {
        printf("Unable to open the database file.\n");
        return 0; // Word not found (error accessing the database file)
    }

    char line[MAX_WORD_LENGTH * 2]; // Twice the max word length to account for commas
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            if (strcmp(token, word) == 0) {
                fclose(file);
                return 1; // Word found in the database
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(file);
    return 0; // Word not found in the database
}

int main() {
    char word[MAX_WORD_LENGTH];

    // time para
    clock_t start, end;
    double execution_time;

    printf("Enter a word to check in the database: ");
    scanf("%s", word);

    start = clock(); // time starts

    if (checkWordInDatabase(word, "database.txt")) {
        printf("The word '%s' is in the database.\n", word);
    } else {
        printf("The word '%s' is not in the database.\n", word);
    }

    end = clock(); // time ends
    /* Get the time taken by program to execute in seconds */
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds : %f", duration); // print time

    return 0;
}
