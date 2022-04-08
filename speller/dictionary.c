// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 20000;

// Hash table
node *table[N];

// Check word in dictionary
bool check(const char *word)
{
    // TODO
    //returns true if found else return false
    int index = hash(word);
    //make a cursor which pointing to the head of the hash
    node *cursor = table[index];
    //Looping  through the list until the final node
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Find hash for word
unsigned int hash(const char *word)
{
    //Summurize the value of the characters.
    unsigned int hash = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hash += tolower(word[i]);
        hash = (hash * tolower(word[i])) % N;
    }
    return hash;
}
int count = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // OPEN DICTIONARY FILE and read
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }

    //Initilize new array
    char wordList[LENGTH + 1];
    //while fscanf != EOF print the words into the character array word
    while (fscanf(file, "%s", wordList) != EOF)
    {
        //Keep track how many nodes were made
        count++;
        //for each new node allocate memory.
        node *newNode = malloc(sizeof(node));
        //check for null
        if (newNode == NULL)
        {
            return 1;
        }
        //initialize the new node
        strcpy(newNode->word, wordList);
        newNode->next = NULL;
        int index = hash(wordList);
        //
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        //make new node
        else
        {
            //makes the next the new head
            newNode->next = table[index];
            //points to the new node.
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // keep track of how many nodes have been added.
    return count;
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //Set pointers to NULL then itterate array table to freed
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
