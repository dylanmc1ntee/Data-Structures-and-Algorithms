#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
int countQs1(Node * root);
int countQs2(Node * root);
Node * insert(Node * root, char * word);
int valid(char * word);

struct Node{

    int flag, numStrings;
    Node * children[26];

};

int countQs1(Node * root)
{
    if(root == NULL || root->children['q' - 'a'] == NULL)
    {
        return 0;
    }

    return root->children['q' - 'a']->numStrings;
}

int countQs2(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    int ans = 0;

    if(root->flag == 1)
    {
        ans++;
    }

    for(int i = 0; i < 26; i++)
    {
        ans += countQs2(root->children[i]);
    }

    return ans;
}

Node * insert(Node * root, char * word)
{
    if(root == NULL)
    {
        root = (Node *) calloc(1, sizeof(Node));
    }

    if(word[0] == '\0')
    {
        root->flag++;
        return root;
    }

    int index = word[0] - 'a';
    root->children[index] = insert(root->children[index], &(word[1]));

    root->numStrings++;

    return root;
}

int valid(char * word)
{
    for(int i = 0; word[i]; i++)
    {
        if(word[i] < 'a' || word[i] > 'z')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    FILE * ifp;
    Node * root = NULL;

    ifp = fopen("words.txt", "r");
    char word[1000];
    while(EOF != fscanf(ifp, "%s", word))
    {
        if(valid(word))
        {
            root = insert(root, word);
        }
    }

    int value = 0;
    for(int i = 0; i < 100; i++)
    {
        value += countQs1(root);
    }

    printf("There are %d words that start with the letter q.\n", value);

    return 0;
}