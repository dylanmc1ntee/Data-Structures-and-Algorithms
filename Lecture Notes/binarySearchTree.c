#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node Node;

struct Node{

    char * data;
    Node * left, * right;

};

Node * createNode(char * data)
{
    Node * res = (Node *) malloc(sizeof(Node));
    res->left = NULL;
    res->right = NULL;
    res->data = strdup(data);
    return res;
}

Node * insertName(Node * root, char * name)
{
    if(root == NULL)
    {
        return createNode(name);
    }

    int res = strcmp(root->data, name);

    if(res > 0)
    {
        root->left = insertName(root->left, name);
    }
    if(res < 0)
    {
        root->right = insertName(root->right, name);
    }

    return root;
}

int contains(Node * root, char * name)
{
    if(root == NULL)
    {
        printf("%s is not in the tree.\n", name);
        return 0;
    }

    int res = strcmp(root->data, name);

    if(res == 0)
    {
        printf("%s is in the tree.\n", name);
        return 1;
    }
    if(res > 0)
    {
        return contains(root->left, name);
    }
    if(res < 0)
    {
        return contains(root->right, name);
    }
}

int main()
{
    Node * root = NULL;

    root = insertName(root, "Alice");
    contains(root, "Alice");
    root = insertName(root, "Alex");
    contains(root, "Alex");
    root = insertName(root, "Carol");
    contains(root, "Carol");
    root = insertName(root, "Bob");
    contains(root, "Bob");
    root = insertName(root, "David");
    contains(root, "David");
    root = insertName(root, "Eric");
    contains(root, "Eric");

    return 0;
}