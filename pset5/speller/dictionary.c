// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 200;

// Hash table
node *table[N];

// counter of words in dict
int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int index = hash(word);

    node *checker = table[index];
    while (checker != NULL)
    {
        if (strcasecmp(checker->word, word) != 0)
        {
            checker = checker->next;
        }
        else
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int points = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        points += toupper(word[i]) - 'A';
    }
    return points % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("not able to open dictionary\n");
        return false;
    }

    char tmp[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", tmp) != EOF)
    {
        node *n_word = malloc(sizeof(node));
        if (n_word == NULL)
        {
            return false;
        }

        strcpy(n_word->word, tmp);
        int index = hash(tmp);

        n_word->next = table[index];
        table[index] = n_word;

        counter++;
    }

    // Close the dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
