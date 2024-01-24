#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char origionalString[4000 + 1]; 
    scanf("%s", origionalString);

    int numForbidden;
    scanf("%d", &numForbidden);

    char forbiddenChars[numForbidden];

    for(int i = 0; i < numForbidden; i++)
    {
        scanf(" ");
        scanf("%c", &forbiddenChars[i]);
    }

    int origionalLen = strlen(origionalString);

    for(int i = 0; i < origionalLen; i++)
    {
        int remove = 0;

        for(int j = 0; j < numForbidden; j++)
        {
            if(origionalString[i] == forbiddenChars[j])
            {
                remove = 1;
                break;
            }
        }

        if(remove == 0)
        {
            printf("%c", origionalString[i]);
        }
    }

    return 0;
}