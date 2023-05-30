#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10000

struct word {
  char *word;
  int hash_value;
};

struct hash_table {
  struct word *words[MAX_WORDS];
};

void init_hash_table(struct hash_table *table) {
  for (int i = 0; i < MAX_WORDS; i++) {
    table->words[i] = NULL;
  }
}

int hash_function(const char *word) {
  int hash_value = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    hash_value = hash_value * 31 + word[i];
  }
  return hash_value;
}

void insert_word(struct hash_table *table, const char *word) {
  int hash_value = hash_function(word);
  struct word *new_word = malloc(sizeof(struct word));
  new_word->word = strdup(word);
  new_word->hash_value = hash_value;
  table->words[hash_value] = new_word;
}

struct word *search_word(struct hash_table *table, const char *word) {
  int hash_value = hash_function(word);
  struct word *found_word = NULL;
  if (hash_value < MAX_WORDS) {
    found_word = table->words[hash_value];
  }
  return found_word;
}

int main() {
  struct hash_table table;
  init_hash_table(&table);

  // Get the word from the user.
  char word[100];
  printf("Enter a word: ");
  fgets(word, 100, stdin);
  word[strlen(word) - 1] = '\0';

  // Insert the word into the hash table.
  insert_word(&table, word);

  // Search for the word in the hash table.
  struct word *found_word = search_word(&table, word);
  if (found_word != NULL) {
    printf("Found word: %s\n", found_word->word);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}
