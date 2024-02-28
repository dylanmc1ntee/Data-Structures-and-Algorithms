#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define numFamily 3

void findMaxHappy(int ** initialHappiness, int ** relationship, int ** combo, int numCats)
{
    for(int i = 0; i < numCats)
    {
        
    }
}

int main()
{
    // get the number of cats
    int numCats;
    scanf("%d", &numCats);

    /*
        Create an array to hold the initial happiness levels of the
        cats, and then gets those levels from the user and store it
    */
    int ** initialHappiness = (int **) malloc(sizeof(int *) * numFamily);
    for(int i = 0; i < numFamily; i++)
    {
        initialHappiness[i] = (int *) malloc(sizeof(int) * numCats);
        for(int j = 0; j < numCats; j++)
        {
            int happy;
            scanf("%d", &happy);
            initialHappiness[i][j] = happy;
        }
    }

    /*
        Create an array to hold the relationships that the cats have
        with eachother, gets those values from the user and store it
    */
    int ** relationship = (int **) malloc(sizeof(int *) * numCats);
    for(int i = 0; i < numCats; i++)
    {
        relationship[i] = (int *) malloc(sizeof(int) * numCats);
        for(int j = 0; j < numCats; j++)
        {
            int happy;
            scanf("%d", &happy);
            relationship[i][j] = happy;
        }
    }

    int ** combo = (int **) malloc(sizeof(int *) * numFamily);
    for(int i = 0; i < numFamily; i++)
    {
        combo[i] = (int *) malloc(sizeof(int) * numCats);
    }

    findMaxHappy(initialHappiness, relationship, combo, numCats);

    // Free initialHappiness Array
    for(int i = 0; i < numFamily; i++)
    {
        free(initialHappiness[i]);
    }
    free(initialHappiness);

    // Free relationship Array
    for(int i = 0; i < numCats; i++)
    {
        free(relationship[i]);
    }
    free(relationship);

    return 0;
}