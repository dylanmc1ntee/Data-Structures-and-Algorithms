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

int main()
{
    int numShops, BTS_Wealth;
    scanf("%d %d", &numShops, &BTS_Wealth);

    int * shops = (int *) malloc(sizeof(int) * numShops);
    for(int i = 0; i < numShops; i++)
    {
        scanf("%d", &shops[i]);
    }

    return 0;
}