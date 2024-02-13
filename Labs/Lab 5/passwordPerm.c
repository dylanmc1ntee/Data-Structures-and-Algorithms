#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define letters "adeflr"

void permute(int permArr[], int used[], int curIndex, int max)
{
    static int count = 1;

    // base case
    if(curIndex == max)
    {
        printf("%d. ", count);

        for(int i = 0; i < max; i++)
        {
            printf("%c", letters[permArr[i]]);
        }
        
        printf("\n");
        count++;
        return;
    }

    // recursive call
    for(int i = 0; i < max; i++)
    {
        if(!used[i])
        {
            permArr[curIndex] = i; // try all possible values
            used[i] = 1;
            permute(permArr, used, curIndex + 1, max);
            used[i] = 0; // next time we loop we want to be able to use the value again
        }
    }
}

int main()
{
    int passwordLen = strlen(letters);
    int permArr[passwordLen]; // 0-5
    int used[passwordLen]; // boolean array

    for(int i = 0; i < passwordLen; i++)
    {
        permArr[i] = 0;
        used[i] = 0;
    }

    permute(permArr, used, 0, passwordLen);

    return 0;
}