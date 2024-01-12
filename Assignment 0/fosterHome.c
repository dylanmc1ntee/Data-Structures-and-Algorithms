#include<stdio.h>
#include<string.h>

void chomp(char word []); //prototype

typedef struct{

    char name[4]; //suffix
    int location, cat;

}family_t; //name of struct

int main() //start of main
{
    int cages, weeks;
    scanf(" %d %d", &cages, &weeks); //scans input
    //creates enough room for longest possible name
    char arr[cages][20 + (weeks * 3)];

    //for the number of cats
    for(int i = 0; i <= cages; i++)
    {
        char str[20];

        fgets(str, 20, stdin); //get their name

        chomp(str); //remove newline

        strcpy(arr[i], str);
    }

    //declare families
    family_t f1;
    family_t f2;
    family_t f3;

    //assign suffix to each family
    strcpy(f1.name, "Lee");
    strcpy(f2.name, "Lyn");
    strcpy(f3.name, "Eve");

    //assign starting location
    f1.location = 1;
    f2.location = 2;
    f3.location = 3;

    //assign which cat they start with
    f1.cat = 1;
    f2.cat = 2;
    f3.cat = 3;

    //for however many weeks
    for(int i = 1; i < weeks; i++)
    {
        //add suffix to cat and move 2 cages
        strcat(arr[f1.cat], f1.name);
        f1.location = f1.location + 2;
        
        //brings them back to beginning if they get to the end
        if(f1.location != cages)
        {
            f1.location = f1.location % cages;
        }

        //if there is a cat available
        if((f1.location != f2.cat) && (f1.location != f3.cat))
        {
            f1.cat = f1.location; //gives them cat
        }
        else
        {
            f1.cat = 0; //they have no cat
        }

        //add suffix to cat and move 3 cages
        strcat(arr[f2.cat], f2.name);
        f2.location = f2.location + 3;

        //brings them back to beginning if they get to the end
        if(f2.location != cages)
        {
            f2.location = f2.location % cages;
        }

        //if there is a cat available
        if((f2.location != f1.cat) && (f2.location != f3.cat))
        {
            f2.cat = f2.location; //gives them cat
        }
        else
        {
            f2.cat = 0; //they have no cat
        }

        //add suffix to cat and move 5 cages
        strcat(arr[f3.cat], f3.name);
        f3.location = f3.location + 5;

        //brings them back to beginning if they get to the end
        if(f3.location != cages)
        {
            f3.location = f3.location % cages;
        }

        //if there is a cat available
        if((f3.location != f2.cat) && (f3.location != f1.cat))
        {
            f3.cat = f3.location; //gives them cat
        }
        else
        {
            f3.cat = 0; //they have no cat
        }
    }

    //for every cage
    for(int i = 1; i <= cages; i++)
    {
        //if there is no cat in the cage
        if((i == f1.cat) || (i == f2.cat) || (i == f3.cat))
        {
            printf("No cat found.\n");
        }
        else
        {
            printf("%s\n", arr[i]);
        }
    }

    return 0;
}

void chomp(char word []) //start of function
{
    if(word[strlen(word) - 1] == '\n') //if last line == to \n
    {
        word[strlen(word) - 1] = '\0'; //replace with null
    }
} //end of function

