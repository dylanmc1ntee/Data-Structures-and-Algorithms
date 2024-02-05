#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int size, cap;
    int * arr;

} ArrayList;

ArrayList * createArrayList()
{
    ArrayList * res = (ArrayList *) malloc(sizeof(ArrayList));

    res->cap = 4;
    res->size = 0;
    //res->arr = (int *) malloc();
}