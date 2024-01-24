#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int grade;
    char * name;

} student_t;

typedef struct{

    int size, cap;
    student_t ** arr;

} list_t;

student_t * createStudent(char * name, int grade)
{
    student_t * res = (student_t *) malloc(sizeof(student_t));
    res->name = (char *) malloc(sizeof(char) * (strlen(name + 1)));
    strcpy(res->name, name);
    res->grade = grade;

    return res;
}

void append(list_t * list, char * name, int grade)
{
    if(list->cap == list->size)
    {
        list->cap *= 2;
        list->arr = (student_t **) realloc(list->arr, sizeof(student_t *) * list->cap);
    }

    list->arr[list->size] = createStudent(name, grade);
    list->size++;
}