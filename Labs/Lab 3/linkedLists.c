#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    int data;
    Node * next;

} Node;

Node * removeAll(int value, Node * head)
{
    Node * newHead = head;
    Node * prevNode;
    Node * tmp;

    while(newHead != NULL && newHead->data == value)
    {
        tmp = newHead;
        newHead = newHead->next;
        free(tmp);
    }

    prevNode = newHead;

    while(prevNode != NULL && prevNode->next != NULL)
    {
        if(prevNode->next->data == value)
        {
            tmp = prevNode->next;
            prevNode->next = tmp->next;
            free(tmp);
        }
        else
        {
            prevNode = prevNode->next;
        }
    }

    return newHead;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    return 0;
}