#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {

char name[20];
int birthYear;
int publishings;

} author_t;

typedef struct {

char name[20];
int year;
int numAuthors;
author_t * authors;

} book_t;

book_t * readLib(int * numBookPtr)
{
    scanf("%d", numBookPtr);
    book_t * result = (book_t *)(malloc((*numBookPtr) * sizeof(book_t)));
    for(int i = 0; i < (*numBookPtr); i++)
    {
        scanf("%s %d %d", result[i].name, &result[i].year, &result[i].numAuthors);
        result[i].authors = (author_t *)(malloc(sizeof(author_t) * result[i].numAuthors));
        for(int j = 0; j < result[i].numAuthors; j++)
        {
            scanf("%s %d %d", result[i].authors[j].name, &(result[i].authors[j].birthYear), &(result[i].authors[j].publishings));
        }
    }

    return result;
}

void printLib(book_t * array, int numBooks)
{
    for(int i = 0; i < numBooks; i++)
    {
        printf("The book is named: \"%s\"\n", array[i].name);
        printf("The authors are: \n");
        for(int j = 0; j < array[i].numAuthors; j++)
        {
            printf("%s\n", array[i].authors[j].name);
        }
        if(i != numBooks - 1)
        {
            printf("\n");
        }
    }
}

void freeAll(book_t * books, int numBooks)
{
    for(int i = 0; i < numBooks; i++)
    {
        free(books[i].authors);
        books[i].authors = NULL;
    }
    free(books);
    books = NULL;
}

int main()
{
    int numBooks;
    book_t * arr = readLib(&numBooks);
    printLib(arr, numBooks);

    return 0;
}