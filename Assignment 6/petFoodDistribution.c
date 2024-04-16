#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// prototypes
typedef struct Node Node;
Node * insert(Node * root, char * word, int amount);
int findMin(Node * root, char * word);
int findMax(Node * root, char * word);
void freeWholeTrie(Node * root);

// Node struct for tries
struct Node{

    int subTrieAmount, myAmount;
    Node * children[32];

};

// Inserts a node into trie
Node * insert(Node * root, char * word, int amount)
{
    // routine null check
    if(root == NULL)
    {
        root = (Node *) calloc(1, sizeof(Node));
    }

    // if the word is over
    // base case
    if(word[0] == '\0')
    {
        root->myAmount += amount;
        return root;
    }

    // converts the letter or number
    // into correct index 0-32
    int index;
    if(isdigit(word[0]) == 1)
    {
        index = (int)(word[0]);
    }
    else
    {
        index = word[0] - 'a' + 10;
    }

    // recursive call
    root->children[index] = insert(root->children[index], &(word[1]), amount);
    root->subTrieAmount += amount;

    return root;
}

// finds min sum
int findMin(Node * root, char * word)
{
    int len = strlen(word);
    int index;
    Node * tmp = root;

    // for the length of the word
    // that is given
    for(int i = 0; i < len; i++)
    {
        // converts the letter or number
        // into correct index 0-32
        if(isdigit(word[i]) == 1)
        {
            index = (int)(word[i]);
        }
        else
        {
            index = word[i] - 'a' + 10;
        }

        // null check
        if(tmp->children[index] == NULL) 
        {
            return 0;
        }

        // moves pointer through trie
        tmp = tmp->children[index];
    }

    return tmp->subTrieAmount;
}

// finds max sum
int findMax(Node * root, char * word)
{
    int len = strlen(word);
    int index;
    Node * tmp = root;
    int sum = 0;

    // for the length of the word
    // that is given
    for(int i = 0; i < len; i++)
    {
        // converts the letter or number
        // into correct index 0-32
        if(isdigit(word[i]) == 1)
        {
            index = (int)(word[i]);
        }
        else
        {
            index = word[i] - 'a' + 10;
        }

        // add current nodes 
        // value to sum counter
        sum += tmp->myAmount;

        // null check
        if(tmp->children[index] == NULL) 
        {
            return tmp->subTrieAmount + sum;
        }

        tmp = tmp->children[index];
    }

    return tmp->subTrieAmount + sum;
}

// frees all dynamic memory
void freeWholeTrie(Node * root)
{
    if(root == NULL) return;

    for(int i = 0; i < 32; i++)
    {
        freeWholeTrie(root->children[i]);
    }

    free(root);
}

int main()
{
    char inp[7];
    char response[100000], newResponse[100000];
    int amount;
    Node * root = NULL;

    // scan initial response
    scanf("%s", inp);

    // while user does
    // not input QUIT
    while(strcmp(inp, "QUIT") != 0)
    {
        // is user responds ADD
        if(strcmp(inp, "ADD") == 0)
        {
            scanf("%s %d", response, &amount);
            root = insert(root, response, amount);
        }
        // if user responds CHANGE
        else if(strcmp(inp, "CHANGE") == 0)
        {
            scanf("%s %s", response, newResponse);
        }
        // if user responds SUM
        else if(strcmp(inp, "SUM") == 0)
        {
            scanf("%s", response);
            int min = findMin(root, response);
            int max = findMax(root, response);
            printf("%d %d\n", min, max);
        }
        else
        {
            // user responds with
            // invalid input
        }

        // scan new response
        scanf("%s", inp);
    }

    // free DMA
    freeWholeTrie(root);
    root = NULL;

    return 0;
}