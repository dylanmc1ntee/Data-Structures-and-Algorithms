#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define numFamily 3

void findMaxHappy(int arr1Cat, int arr1Fam, int arr2Cat1, int arr2Cat2, int initialHappiness[arr1Cat][arr1Fam], int relationship[arr2Cat1][arr2Cat2])
{
    
}

int main()
{
    int numCats;
    scanf("%d", &numCats);

    int initialHappiness[numCats][numFamily];
    for(int i = 0; i < numFamily; i++)
    {
        for(int j = 0; j < numCats; j++)
        {
            int happy;
            scanf("%d", &happy);
            initialHappiness[i][j] = happy;
        }
    }

    int relationship[numCats][numCats];
    for(int i = 0; i < numCats; i++)
    {
        for(int j = 0; j < numCats; j++)
        {
            int happy;
            scanf("%d", &happy);
            relationship[i][j] = happy;
        }
    }

    return 0;
}