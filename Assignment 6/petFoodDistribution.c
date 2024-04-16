#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Node Node;
Node * insert(Node * root, char * word, int amount);
int findMin(Node * root, char * word);
int findMax(Node * root, char * word);
void freeWholeTrie(Node * root);

struct Node{

    int subTrieAmount, myAmount;
    Node * children[32];

};

Node * insert(Node * root, char * word, int amount)
{
    if(root == NULL)
    {
        root = (Node *) calloc(1, sizeof(Node));
    }

    if(word[0] == '\0')
    {
        root->myAmount = amount;
        return root;
    }

    int index;
    if(isdigit(word[0]) == 1)
    {
        index = (int)(word[0]);
    }
    else
    {
        index = word[0] - 'a' + 10;
    }

    root->children[index] = insert(root->children[index], &(word[1]), amount);
    root->subTrieAmount += amount;

    return root;
}

// returns 0 when it shouldnt
int findMin(Node * root, char * word)
{
    int len = strlen(word);
    int index;
    Node * tmp = root;

    for(int i = 0; i < len; i++)
    {
        if(isdigit(word[0]) == 1)
        {
            index = (int)(word[0]);
        }
        else
        {
            index = word[0] - 'a' + 10;
        }

        if(tmp->children[index] == NULL) 
        {
            return 0;
        }

        tmp = tmp->children[index];
    }

    return tmp->subTrieAmount;
}

// returns the number from A, which includes a1
int findMax(Node * root, char * word)
{
    int index;

    if(isdigit(word[0]) == 1)
    {
        index = (int)(word[0]);
    }
    else
    {
        index = word[0] - 'a' + 10;
    }

    if(root->children[index] == NULL)
    {
        return 0;
    }

    return root->children[index]->subTrieAmount;
}

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

    scanf("%s", inp);
    while(strcmp(inp, "QUIT") != 0)
    {
        if(strcmp(inp, "ADD") == 0)
        {
            scanf("%s %d", response, &amount);
            root = insert(root, response, amount);
        }
        else if(strcmp(inp, "CHANGE") == 0)
        {
            scanf("%s %s", response, newResponse);
        }
        else if(strcmp(inp, "SUM") == 0)
        {
            scanf("%s", response);
            int min = findMin(root, response);
            int max = findMax(root, response);
            printf("%d %d\n", min, max);
        }
        else
        {
            // invalid
        }

        scanf("%s", inp);
    }

    freeWholeTrie(root);
    root = NULL;

    return 0;
}