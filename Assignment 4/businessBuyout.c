#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//scan input for number of shops and initial wealth
//create a list of size N to hold the wealth of shops
//scan input for the wealth of N shops

//sort the list of shops from least to most wealthy
//create stack

/*
    for(i < length of sorted list) go through the list and add to stack the ones that can be bought, 
    once you reach one you cant buy, buy the shop at the top of the stack. 

    add wealth to BTS
    remove old shop from array

    After each buy, check to see if they are the wealthiest
*/
//after the loop, if they still arent the wealthiest, return -1

typedef struct Stack Stack;

struct Stack {

    int capacity;
    int current;
    int * stackArr;

};

void push(Stack * s1, int num)
{
    if(s1->current == s1->capacity - 1)
        return;

    s1->stackArr[++s1->current] = num;
}

void pop(Stack * s1)
{
    if(s1->current == -1)
        return;

    s1->current--;
}

void clearFromStack(Stack * s1)
{
    if(s1->current == -1)
        return;

    while(s1->current != -1)
    {
        s1->current--;
    }
}

void removeFromArray(int * shops, int count, int numShops)
{
    for(int i = count - 1; i < numShops - 1; i++)
    {
        shops[i] = shops[i + 1];
    }
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

int buyShop(Stack * s1, int * arr, int count, int BTS_Wealth, int numShops)
{
    int sum = BTS_Wealth + s1->stackArr[count - 1];
    pop(s1);

    removeFromArray(arr, count, numShops);
    return sum;
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

    Stack wealthStack;
    wealthStack.stackArr = (int *) malloc(sizeof(int) * numShops);
    wealthStack.capacity = numShops;
    wealthStack.current = -1;

    mergeSort(shops, 0, numShops - 1);

    int numBought = 0;
    int wealthy = -1;

    while(wealthy != 1)
    {
        int count = 0;
        while(BTS_Wealth > shops[count])
        {
            push(&wealthStack, shops[count]);
            count++;
        }

        if(count == 0)
        {
            break;
        }
        else
        {
            BTS_Wealth = buyShop(&wealthStack, shops, count, BTS_Wealth, numShops);
            numBought++;
            numShops--;

            clearFromStack(&wealthStack);

            int isWealthiest = 1;
            for(int i = 0; i < numShops; i++)
            {
                if(shops[i] > BTS_Wealth)
                {
                    isWealthiest = 0;
                }
            }

            if(isWealthiest == 1)
            {
                wealthy = 1;
            }
        }
    }

    if(wealthy == 1)
    {
        printf("%d\n", numBought);
    }
    else
    {
        printf("-1\n");
    }

    free(shops);
    shops = NULL;
    free(wealthStack.stackArr);
    wealthStack.stackArr = NULL;

    return 0;
}