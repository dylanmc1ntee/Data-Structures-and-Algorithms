#include <stdio.h>
#include <stdlib.h>

typedef struct Heap Heap;
#define PARENT(x) (((x)-1)/2)

struct Heap {

    int size, cap;
    int * arr;

};

void append(Heap * h, int value)
{
    if(h->size == h->cap)
    {
        h->cap *= 2;
        h->arr = realloc(h->arr, h->cap * sizeof(int));
    }
    h->arr[h->size] = value;
    h->size++;
}

void percolate(Heap * h, int index)
{
    while(index != 0 && h->arr[index] > h->arr[PARENT(index)])
    {
        // not finished
    }
}

void insert(Heap * h, int value)
{
    append(h, value);
}

void printHeap(Heap * h)
{
    for(int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

Heap * createHeap()
{
    Heap * res;
    res = (Heap *) calloc(1, sizeof(Heap));

    res->cap = 1;
    res->arr = (int *) malloc(sizeof(int) * res->cap);

    return res;
}

void * deleteHeap(Heap * h)
{
    free(h->arr);
    free(h);
}

int main()
{
    Heap * h = createHeap();

    insert(h, 8);
    insert(h, 6);
    insert(h, 7);
    insert(h, 5);
    insert(h, 3);
    insert(h, 0);
    insert(h, 9);

    printHeap(h);

    deleteHeap(h);

    return 0;
}