// SELECTION SORT

#include<stdio.h>
#include<stdlib.h>

#define LEN 20
#define MAX 100

// create array
int * genArray(int len)
{
    int * res = (int *) malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++)
    {
        res[i] = rand() % (MAX + 1);
    }
    return res;
}

// Selection Sort (Recursive)
void sortArray(int * arr, int len)
{
    if(len <= 1)
    {
        return;
    }

    // find min
    int index = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[index] > arr[i])
        {
            index = i;
        }
    }

    // swap
    int tmp = arr[index];
    arr[index] = arr[0];
    arr[0] = tmp;

    // recursive
    sortArray(arr + 1, len -1);
}

void printArray(int * arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int * arr = genArray(LEN);

    return 0;
}