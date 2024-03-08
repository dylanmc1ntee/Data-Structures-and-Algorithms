#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack Stack;

struct Stack {

    int capacity;
    int current;
    int * stackArr;

};

// pushes number on to the stack
void push(Stack * s1, int num)
{
    if(s1->current == s1->capacity - 1)
        return;

    s1->stackArr[++s1->current] = num;
}

// pop top number on the stack
void pop(Stack * s1)
{
    if(s1->current == -1)
        return;

    s1->current--;
}

// pops all numbers in the stack
void clearFromStack(Stack * s1)
{
    if(s1->current == -1)
        return;

    while(s1->current != -1)
    {
        s1->current--;
    }
}

// removes a specific shop from array of shops
void removeFromArray(int * shops, int count, int numShops)
{
    for(int i = count - 1; i < numShops - 1; i++)
    {
        shops[i] = shops[i + 1];
    }
}

// merges 2 sorted arrays into 1 array
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

// recursively sorts the given array using merge sort
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

// simulates buying a shop
int buyShop(Stack * s1, int * arr, int count, int BTS_Wealth, int numShops)
{
    int sum = BTS_Wealth + s1->stackArr[count - 1];
    pop(s1);

    removeFromArray(arr, count, numShops);
    return sum;
}

int main()
{
    // gets the number of shops and initial wealth of BTS
    int numShops, BTS_Wealth;
    scanf("%d %d", &numShops, &BTS_Wealth);

    // scan in the wealth of N shops
    int * shops = (int *) malloc(sizeof(int) * numShops);
    for(int i = 0; i < numShops; i++)
    {
        scanf("%d", &shops[i]);
    }

    // creates the stack
    Stack wealthStack;
    wealthStack.stackArr = (int *) malloc(sizeof(int) * numShops);
    wealthStack.capacity = numShops;
    wealthStack.current = -1;

    // sort the shops array from least wealth to greatest
    mergeSort(shops, 0, numShops - 1);

    int numBought = 0;
    int wealthy = -1;

    // while BTS is not the wealthiest
    while(wealthy != 1)
    {
        int count = 0;
        // push all shops that BTS can buy into stack
        while(BTS_Wealth > shops[count])
        {
            push(&wealthStack, shops[count]);
            count++;
        }

        // if BTS cannot buy any shops then break
        if(count == 0)
        {
            break;
        }
        else
        {
            // buy the biggest shop
            BTS_Wealth = buyShop(&wealthStack, shops, count, BTS_Wealth, numShops);
            numBought++;
            numShops--;

            // remove the bought shop from shops array
            clearFromStack(&wealthStack);

            int isWealthiest = 1;
            // for all the shops still in the array
            for(int i = 0; i < numShops; i++)
            {
                // if a shop is wealthier than BTS
                if(shops[i] > BTS_Wealth)
                {
                    isWealthiest = 0;
                }
            }

            // if BTS is the wealthiest
            if(isWealthiest == 1)
            {
                wealthy = 1;
            }
        }
    }

    // if BTS is the wealthiest
    if(wealthy == 1)
    {
        printf("%d\n", numBought);
    }
    // if BTS is not the wealthiest
    else
    {
        printf("-1\n");
    }

    // free DMA
    free(shops);
    shops = NULL;
    free(wealthStack.stackArr);
    wealthStack.stackArr = NULL;

    return 0;
}