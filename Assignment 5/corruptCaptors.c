#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
typedef struct Node Node;
Node * createNode(int x, int hatSize);
Node * insertRaccoon(Node * root, int x, int hatSize);
Node * captureRaccoon(Node * root, int x);
Node * delete(Node * root);
Node * search(Node * root, int x);
Node * rotateLeft(Node * root);
Node * rotateRight(Node * root);
Node * promote(Node * root);
Node * demote(Node * root);
void freeAll(Node * root);
void printTree(Node * root);

// bst node
struct Node{

    Node * parent, * left, * right;
    int x, hatSize;
    long long int foodLevel;

};

// creates a new node
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
    res->foodLevel = 0;

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

// captures raccoon at given location
Node * captureRaccoon(Node * root, int x)
{
    // returns pointer to specific raccoon
    Node * foundRaccoon = search(root, x); 
    printf("%lld\n", foundRaccoon->foodLevel);
    // stores value of hat
    int oldHat = foundRaccoon->hatSize;

    // sets the captured raccoon's hat to -1 and rotates it down
    foundRaccoon->hatSize = -1;
    foundRaccoon = demote(foundRaccoon);

    // sets correct parent pointer to NULL
    if(foundRaccoon->parent != NULL)
    {
        if(foundRaccoon->parent->left == foundRaccoon)
        {
            foundRaccoon->parent->left = NULL;
        }
        else
        {
            foundRaccoon->parent->right = NULL;
        }
    }

    // delete raccoon
    foundRaccoon = delete(foundRaccoon);
    
    return root;
}

// frees data
Node * delete(Node * root)
{
    free(root);
    return NULL;
}

// returns a pointer to the raccoon node
Node * search(Node * root, int x)
{
    Node * tmp = root;

    // while not at correct location
    while(tmp->x != x)
    {
        if(x < tmp->x)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }

    return tmp;
}

// rotates node to left
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

// rotates node to right
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

// rotates a node up until parent hat is not bigger
Node * promote(Node * root)
{
    if(root == NULL || root->parent == NULL)
    {
        return root;
    }

    // while the parents hat size is bigger than the node's
    while(root->hatSize > root->parent->hatSize)
    {
        // if node is on left side
        if(root == root->parent->left)
        {
            root = rotateRight(root->parent);
        }
        // if node is on right side
        else
        {
            root = rotateLeft(root->parent);
        }
    }

    return root;
}

// rotates a node down to bottom
Node * demote(Node * root)
{
    if(root == NULL)
    {
        return root;
    }

    // while node is not a leaf
    while(root->left != NULL && root->right != NULL)
    {
        if(root->left == NULL && root->right != NULL)
        {
            root = rotateLeft(root);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            root = rotateRight(root);
        }
        else if(root->left->hatSize < root->right->hatSize)
        {
            root = rotateLeft(root);
        }
        else
        {
            root = rotateRight(root);
        }
    }

    return root;
}

// frees all dynamic memory
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

// prints the bst
void printTree(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    printTree(root->left);
    printf("%d\n", root->x);
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

        if(strcmp(inp, "CAPTURE") != 0)
        {
            scanf("%d %d", &x, &h);
        }
        else
        {
            scanf("%d", &x);
        }

        if(strcmp(inp, "ADD") == 0)
        {
            root = insertRaccoon(root, x, h);
        }
        
        if(strcmp(inp, "CAPTURE") == 0)
        {
            root = captureRaccoon(root, x);
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