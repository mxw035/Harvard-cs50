// Implements a dictionary's functionality
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

//global
int word_count = 0;

// Represents a node in a hash table
typedef struct node //sets the node
{
    char word[LENGTH + 1]; //is part of node struct
    struct node *next; //creats the next list
}
node;

// Number of buckets in hash table
const unsigned int N = 65536; //creates hashtable size
node *table[N]; //creates the actually hash tabel

//int hash_index(char *hash_this);

node *head = NULL; //declare pointer head with empty node

// Hash table
//node *table[N]; //table is set to N which is now 26

// Returns true if word is in dictionary, else false

// Hashes word to a number
//this hash fxn was obtained from github by srushtikanade
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash = 5381; //creates an usigned int called hash orginally setting it to 0
    int c = *word;
    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open file to start
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        //printf("Could not open dictionary file load fxn erorr 1");
        return false;
        fclose(dic); //chagned from unload() which is had previously
    }

    //get ready to read need to make word
    char word[LENGTH + 1];
    //int word_count = 0;

    while (fscanf(dic, "%s", word) != EOF)// this is a while loop that scans the file for words till it reaches the end of file
    {
        //now we have words and need to creat nodes
        node *new_word = malloc(sizeof(node)); //set aside memory for new word to the space of null
        //check if null
        if (new_word == NULL)
        {
            //printf("Node n is null load fxn error 2");
            fclose(dic);
            return false;

        }
        //assign word to new node
        strcpy(new_word->word, word); //sets the new node to word
        //printf("Word test load fxn after strcpy: %s\n", word); //printed cat
        new_word->next = NULL;

        //so now we have open file to read checked for null, created char word, scanned the reading file for words, created a new null
        //for the words and assigned the words to new null. still need to get hash and set to table.
        unsigned int index = hash(word); //want to get a hash int for new word set that to int h to be used later// dosent work right now
        //int h = hash(word); //hash fxn need to take the input of char word which has been set to n
        //printf("Hash int test: %i\n", h); //test to see if the hash fxn worked should return 0 at this time //worked printed 0

        //now we have the hash int we need to created the list a the array spot on hash table
        //n->word = table[H]; //would this assign to table
        //check if null
        new_word->next = table[index];
        table[index] = new_word;

        word_count++;
    }
    fclose(dic);
    return true;
    //return false;
}


bool check(const char *word) //takes input of char* word
{
    // TODO
    //hash word for int
    int n = strlen(word); //gets the lenght of the word/string/char* in question

    char copy[LENGTH + 1]; //creates a new string to copy the word
    copy[n] = '\0';

    //set up for loop to copy word
    for (int i = 0; i < n; i++)
    {
        copy[i] = tolower(word[i]); //trying to copy word
    }
    //word_copy[n] = '\0';

    int h = hash(copy); //get hash int for word

    //create the cursor to transverse linked list
    node *cursor = table[h]; // creates a pointer called cursor that points to hashtable array h linked list
    //this will be int h refering to the word copy
    if (cursor == NULL)
    {
        return false;
    }


    //access int array and linked list
    while (cursor != NULL) //while cursor does not equal null, meaning that it does have data i it.
    {
        if (strcasecmp(cursor->word, copy) == 0) // checks if the comparison of string of the cursor word is same as copy word
            //reuturn true
        {
            return true; //if equal returns true stating it is in the dictionary
        }
        else // if not equal
        {
            cursor = cursor->next; //moves on to next word in linked list
        }
    }

    //return true

    return false; //returns false
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) //size fxn takes input of void and output of unasigned txt
{
    // TODO
    //printf("word count fxn size: %i\n", word_count); //is not getting to this part of the program why?
    return word_count; //my code same as example i found this just returns the continuing word count we have adding to

    //return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) //no input out put = bool true if able to free false when reaches null
//nodes created hashtable, n, head, cursor
{
    // TODO
    //for loop to go through hashtable

    for (int i = 0; i < N; i++) //sets loop to go through table
    {
        node *temp1 = table[i]; // sets up a temporary pointer that points to tabel[i]
        while (temp1 != NULL) //if the pointer has data
        {
            node *temp2 = temp1; //create a new temporary set same location as temp 1
            temp1 = temp1->next; // set temp 1 to next in the linked list
            free(temp2); //free temp2 or the orginal head of list while not orphaning the other nodes
        }

    }
    return true; //return true to main fxn
}
