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
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];
unsigned int word_count = 0;

// Hashes the word (hash function posted on reddit by delipity)
// The word you want to hash is contained within new node, arrow, word.
// Hashing that will give you the index. Then you insert word into linked list.
int hash_index(char *hash_this)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hash_this); i < n; i++)
    {
        hash = (hash << 2) ^ hash_this[i];
    }
    return hash % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int n = strlen(word);
    char copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        copy[i] = tolower(word[i]);
    }
    // Adds null terminator to end string
    copy[n] = '\0';
    int ind = hash_index(copy);

    // Set pointer to bucket

    node *head = table[ind];

    while (head != NULL)
    {
        if (strcasecmp(head->word, word) == 0)
        {
            return true;
        }

        head = head->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dict
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Can't load dictionary");
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }

        // Copy the word into the node
        strcpy(n->word, word);

        // Has word to put into buckets
        int ind = hash_index(n->word);

        n->next = table[ind];
        table[ind] = n;
        word_count++;

    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Clear each bucket at a time
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            free(temp);
        }
    }
    return true;
}
