// Double Circular Linked Linked Lists

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    Node * next;
    Node * prev;
} Node;

Node * createNode(int value)
{
    Node * res = (Node *) malloc(sizeof(Node));
    res->data = value;

    //CIRCULAR
    res->next = res;
    res->prev = res;

    return res;
}

Node * insertHead(Node * tail, int data)
{
    Node * newHead = createNode(data);

    if(!tail)
    {
        return newHead;
    }

    Node * oldHead = tail->next;
    Node * oldTail = tail;
    oldTail->next = newHead;
    oldHead->prev = newHead;
    newHead->next = oldHead;
    newHead->prev = oldTail;

    return oldTail;
}

Node * insertTail(Node * tail, int data)
{
    return insertHead(tail, data)->next;
}

Node * removeHead(Node * tail)
{
    if(tail == NULL)
    {
        return NULL;
    }
    if(tail->next == tail)
    {
        free(tail);
        return NULL:
    }

    Node * oldHead = tail->next;
    Node * newHeadm= oldHead->next;

    free(oldHead);

    newHead->prev = tail;
    tail->next = newHead;

    return tail;
}

int main()
{

    return 0;
}
