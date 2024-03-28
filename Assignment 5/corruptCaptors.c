#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
Node * createNode(int x, int hatSize);
Node * insertRaccoon(Node * root, int x, int hatSize);
Node * rotateLeft(Node * root);
Node * rotateRight(Node * root);
Node * promote(Node * root);
void freeAll(Node * root);
void printTree(Node * root);

struct Node{

    Node * parent, * left, * right;
    int x, hatSize;
    long long int foodLevel;

};

Node * createNode(int x, int hatSize)
{
    // create node
    Node * res = (Node *) malloc(sizeof(Node));

    // set all pointers to null
    res->parent = NULL;
    res->left = NULL;
    res->right = NULL;

    // set other data to data given
    res->x = x;
    res->hatSize = hatSize;

    return res;
}

Node * insertRaccoon(Node * root, int x, int hatSize)
{
    // if it is an empty node
    if(root == NULL)
    {
        return createNode(x, hatSize);
    }

    // if location is less than root location
    if(x < root->x)
    {
        // recursive call
        Node * left = insertRaccoon(root->left, x, hatSize);
        root->left = left;
        left->parent = root;

        root = promote(root);
    }

    // if location is greater than root location
    if(x > root->x)
    {
        // recursive call
        Node * right = insertRaccoon(root->right, x, hatSize);
        root->right = right;
        right->parent = root;

        root = promote(root);
    }

    return root;
}

Node * rotateLeft(Node * root)
{
    Node * parent = root->parent;
    Node * tmp = root->right;
    root->right = tmp->left;

    if(tmp->left != NULL)
    {
        tmp->left->parent = root;
    }

    tmp->left = root;
    root->parent = tmp;
    tmp->parent = parent;

    if(parent == NULL)
    {
        if(parent->right == root)
        {
            parent->right = tmp;
        }
        else
        {
            parent->left = tmp;
        }
    }

    return tmp;
}

Node * rotateRight(Node * root)
{
    Node * parent = root->parent;
    Node * tmp = root->left;
    root->left = tmp->right;

    if(tmp->right != NULL)
    {
        tmp->right->parent = root;
    }

    tmp->right = root;
    root->parent = tmp;
    tmp->parent = parent;

    if(parent == NULL)
    {
        if(parent->left == root)
        {
            parent->left = tmp;
        }
        else
        {
            parent->right = tmp;
        }
    }

    return tmp;
}

Node * promote(Node * root)
{
    if(root == NULL || root->parent == NULL)
    {
        return root;
    }

    while(root->hatSize > root->parent->hatSize)
    {
        if(root == root->parent->left)
        {
            root = rotateRight(root->parent);
        }
        else
        {
            root = rotateLeft(root->parent);
        }
    }

    return root;
}

void freeAll(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    freeAll(root->left);
    freeAll(root->right);

    free(root);
}

void printTree(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    printTree(root->left);
    printf("%d\n", root->hatSize);
    printTree(root->right);
}

int main()
{
    int x, h;
    char inp[10];
    Node * root = NULL;

    while(1)
    {
        scanf(" %s", inp);

        if(strcmp(inp, "QUIT") == 0)
        {
            break;
        }

        scanf("%d %d", &x, &h);

        if(strcmp(inp, "ADD") == 0)
        {
            root = insertRaccoon(root, x, h);
            printf("~~~~~~~~~~~\n");
            printTree(root);
            printf("~~~~~~~~~~~\n");
        }
        
        if(strcmp(inp, "CAPTURE") == 0)
        {

        }
        
        if(strcmp(inp, "HAT") == 0)
        {

        }
        
        if(strcmp(inp, "STEAL") == 0)
        {

        }
    }

    freeAll(root);
    root = NULL;

    return 0;
}