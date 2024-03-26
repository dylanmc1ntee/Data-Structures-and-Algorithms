#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

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
    // if it is an empty BST
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
    }

    // if location is greater than root location
    if(x > root->x)
    {
        // recursive call
        Node * right = insertRaccoon(root->right, x, hatSize);
        root->right = right;
        right->parent = root;
    }

    return root;
}

int main()
{


    return 0;
}