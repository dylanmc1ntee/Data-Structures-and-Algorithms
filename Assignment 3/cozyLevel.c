#include<stdio.h>
#include<stdlib.h>

int main()
{
    int numCats;
    int numFamilies = 3;

    scanf("%d", &numCats);
    
    int ** origionalHappyLevel[numCats][numFamilies];
    int ** happyWithOthers[numCats][numCats];

    for(int i = 0; i < numCats; i++)
    {
        for(int j = 0; j < numFamilies; j++)
        {
            scanf("%d", origionalHappyLevel[i][j]);
        }
    }

    for(int i = 0; i < numCats; i++)
    {
        for(int j = 0; j < numCats; j++)
        {
            scanf("%d", happyWithOthers[i][j]);
        }
    }

    for(int i = 0; i < numCats; i++)
    {
        for(int j = 0; j < numFamilies; j++)
        {
            printf("%d ", origionalHappyLevel[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < numCats; i++)
    {
        for(int j = 0; j < numCats; j++)
        {
            printf("%d ", happyWithOthers[i][j]);
        }
        printf("\n");
    }

    return 0;
}