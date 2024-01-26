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
    res->next = NULL;
    return res;
}

Node * createList()
{
    Node * head = NULL;

    for(int i = 0; i <= 6; i++)
    {
        Node * newHead = createNode(i);
        newHead->next = head;
        head = newHead;
    }

    for(int i = 7; i >= 1; i-=2)
    {
        Node * newHead = createNode(i);
        newHead->next = head;
        head = newHead;
    }

    return head;
}

void printList(Node * head)
{
    Node * tmp = head;
    while(tmp)
    {
        printf("%d -> ", tmp->data);
        head = head->next;
    }
}

void deleteList(Node * head)
{
    while(head)
    {
        Node * tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main()
{
    Node * list = createList();
    printList(list);

    return 0;
}