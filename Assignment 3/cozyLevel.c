#include<stdio.h>
#include<stdlib.h>

typedef struct Cat Cat;

struct Cat{

    int * origionalHappyLevel;
    int * happyLevelWithCats;

};

int main()
{
    int numCats;
    Cat * catArray = malloc(sizeof(Cat) * numCats);

    for(int i = 0; i < numCats; i++)
    {
        catArray[i].origionalHappyLevel = malloc(sizeof(int) * 3);
        scanf("%d %d %d", catArray[i].origionalHappyLevel[0], catArray[i].origionalHappyLevel[1], catArray[i].origionalHappyLevel[2]);
    }

    for(int i = 0; i < numCats; i++)
    {
        catArray[i].happyLevelWithCats = malloc(sizeof(int) * numCats);

        for(int j = 0; j < numCats; j++)
        {
            scanf("%d", catArray[i].happyLevelWithCats[j]);
        }
    }

    for(int i = 0; i < numCats; i++)
    {
        printf("%d %d %d\n", catArray[i].origionalHappyLevel[0], catArray[i].origionalHappyLevel[1], catArray[i].origionalHappyLevel[2]);
    }

    for(int i = 0; i < numCats; i++)
    {
        for(int j = 0; j < numCats; j++)
        {
            printf("%d ", catArray[i].happyLevelWithCats[j]);
        }

        printf("\n");
    }

    return 0;
}