// Circular Linked Lists

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    Node * next;
} Node;

Node * createNode(int value)
{
    Node * res = (Node *) malloc(sizeof(Node));
    res->data = value;
    res->next = res;

    return res;
}

Node * insertHead(Node * tail, int data)
{
    Node * newHead = createNode(data);

    if(!tail)
    {
        return newHead;
    }

    newHead->next = tail->next;
    tail->next = newHead;
}

Node * insertTail(Node * tail, int data)
{
    return insertHead(tail, data)->next;
}

int main()
{

    return 0;
}
