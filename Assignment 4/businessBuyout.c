#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//scan input for number of shops and initial wealth
//create a list of size N to hold the wealth of shops
//scan input for the wealth of N shops

//sort the list of shops from least to most wealthy
/*
    for(i < length of sorted list) go through the list and add to stack the ones that can be bought, 
    once you reach one you cant buy, buy the shop at the top of the stack. 

    After each buy, check to see if they are the wealthiest
*/
//after the loop, if they still arent the wealthiest, return -1

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

void merge2Arrays(int * arr, int left, int middle, int right)
{
    int index1 = middle - left + 1;
    int index2 = right - middle;

    int leftSide[index1];
    int rightSide[index2];

    int i;
    for(i = 0; i < index1; i++)
        leftSide[i] = arr[left + i];

    int j;
    for(j = 0; j < index2; j++)
        rightSide[j] = arr[middle + 1 + j];

    int k = left;
    i = 0;
    j = 0;

    while(i < index1 && j < index2)
    {
        if(leftSide[i] <= rightSide[j])
        {
            arr[k] = leftSide[i];
            i++;
        }
        else
        {
            arr[k] = rightSide[j];
            j++;
        }
        k++;
    }

    while(i < index1)
    {
        arr[k] = leftSide[i];
        i++;
        k++;
    }

    while(j < index2)
    {
        arr[k] = rightSide[j];
        j++;
        k++;
    }
}

void mergeSort(int * arr, int left, int right)
{
    if(left < right)
    {
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge2Arrays(arr, left, middle, right);
    }
}



int main()
{
    int numShops, BTS_Wealth;
    scanf("%d %d", &numShops, &BTS_Wealth);

    int * shops = (int *) malloc(sizeof(int) * numShops);
    for(int i = 0; i < numShops; i++)
    {
        scanf("%d", &shops[i]);
    }

    printArray(shops, numShops);

    mergeSort(shops, 0, numShops - 1);

    printArray(shops, numShops);

    free(shops);
    shops = NULL;

    return 0;
}