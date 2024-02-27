#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define numFruit 9
#define numBuy 8

void combination(char ** allFruit, char ** basket, int basketIndex, int fruitIndex)
{
    static int count = 1;

    if(basketIndex == numBuy) // filled basket
    {
        printf("%d. ", count);

        for(int i = 0; i < numBuy; i++)
        {
            printf("%s ", basket[i]);
        }

        count++;
        printf("\n");
        return;
    }

    if(fruitIndex == numFruit) // out of fruit
    {
        return;
    }

    basket[basketIndex] = allFruit[fruitIndex];
    combination(allFruit, basket, fruitIndex + 1, basketIndex + 1); //buy the fruit
    combination(allFruit, basket, fruitIndex + 1, basketIndex); // ignore the fruit, dont buy
}

int main()
{
    char ** allFruit = (char**) malloc(sizeof(char *) * numFruit);
    char ** basket = (char**) malloc(sizeof(char *) * numBuy);

    allFruit[0] = "apple";
    allFruit[1] = "banana";
    allFruit[2] = "cantaloupe";
    allFruit[3] = "lemon";
    allFruit[4] = "lime";
    allFruit[5] = "apricot";
    allFruit[6] = "plum";
    allFruit[7] = "grape";
    allFruit[8] = "cucumber";

    combination(allFruit, basket, 0, 0);

    return 0;
}