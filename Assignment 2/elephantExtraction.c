#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node Node;
typedef struct Stack Stack;
typedef struct Elephant Elephant;

struct Node{

    int r, c;
    Node * next;

};

struct Stack{

    Node * head;

};

struct Elephant{

    Stack memory;

};

Node * createNode(int row, int col)
{
    Node * ret;
    ret = (Node *) malloc(sizeof(Node));
    ret->r = row;
    ret->c = col;
    ret->next = NULL;
    return ret;
}

void push(Stack * stack, int row, int col)
{
    Node * newHead = (Node *) malloc(sizeof(Node));
    newHead->r = row;
    newHead->c = col;
    newHead->next = stack->head;
    stack->head = newHead;
}

void pop(Stack * stack)
{
    Node * tmp;
    if(stack->head == NULL) return;
    tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}

void top(Stack stack, int * rowPtr, int * colPtr)
{
    if(stack.head != NULL)
    {
        *rowPtr = stack.head->r;
        *colPtr = stack.head->c;
    }
}

void addBait(int ** grid, int row, int col, int amount)
{
    grid[row][col] = amount;
}

int eatBait(int ** grid, int row, int col)
{
    int food = grid[row][col];
    grid[row][col] = 0;
    return food;
}

void move(Elephant * elephant, int ** grid)
{
    int row;
    int col;
    int * curRow = &row;
    int * curCol = &col;
    int direction = -1;
    int up = 0, down = 0, left = 0, right = 0;

    top(elephant->memory, curRow, curCol);

    if(*curRow != 499 && grid[*curRow + 1][*curCol] > 0)
    {
        right = grid[*curRow + 1][*curCol];
    }
    else if(*curRow != 0 && grid[*curRow - 1][*curCol] > 0)
    {
        left = grid[*curRow - 1][*curCol];
    }
    else if(*curCol != 499 && grid[*curRow][*curCol + 1] > 0)
    {
        down = grid[*curRow][*curCol + 1];
    }
    else if(*curCol != 0 && grid[*curRow][*curCol - 1] > 0)
    {
        up = grid[*curRow][*curCol - 1];
    }
    else
    {

    }

    if(up == 0 && down == 0 && left == 0 && right == 0)
    {
        if(elephant->memory.head->next != NULL)
        {
            pop(&elephant->memory);
        }
    }
    else
    {
        if(up > down && up > left && up > right)
        {
            push(&elephant->memory, *curRow, *curCol - 1);
        }
        if(down > up && down > left && down > right)
        {
            push(&elephant->memory, *curRow, *curCol + 1);
        }
        if(left > down && left > up && left > right)
        {
            push(&elephant->memory, *curRow - 1, *curCol);
        }
        if(right > down && right > left && right > up)
        {
            push(&elephant->memory, *curRow + 1, *curCol);
        }
    }
}

int progressHour(Elephant * elephant, int numElephants, int ** grid)
{
    int numEaten = 0;

    for(int i = 0; i < numElephants; i++)
    {
        int row;
        int col;
        int* curRow = &row;
        int* curCol = &col;

        top(elephant[i].memory, curRow, curCol);

        if(grid[*curRow][*curCol] > 0)
        {
            numEaten += eatBait(grid, row, col);
        }
        else
        {
            move(&elephant[i], grid);
        }
    }

    for(int i = 0; i < numElephants; i++)
    {
        int row;
        int col;
        int* curRow = &row;
        int* curCol = &col;

        top(elephant[i].memory, curRow, curCol);

        if(grid[*curRow][*curCol] > 0)
        {
            numEaten += eatBait(grid, row, col);
        }
    }

    return numEaten;
}

void freeList(Node * head)
{
    Node * tmp;

    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    char command[5];
    int row, col, amount, numElephants;

    //allocate memory for grid
    int ** grid = (int **) malloc(sizeof(int *) * 500);
    for(int i = 0; i < 500; i++)
    {
        grid[i] = (int *) malloc(sizeof(int) * 500);
    }

    //populate grid full of 0s
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            grid[i][j] = 0;
        }
    }

    scanf("%d", &numElephants); //get num elephants

    Elephant * elephantList = (Elephant *) malloc(sizeof(Elephant) * numElephants); //create array of elephants

    //get their origional placements
    for(int i = 0; i < numElephants; i++)
    {
        scanf("%d %d", &row, &col);
        elephantList[i].memory.head = createNode(row, col);
    }

    //scan first command
    scanf("%s", command);

    while(strcmp(command, "QUIT") != 0)
    {
        //if more input is needed
        if(strcmp(command, "BAIT") == 0)
        {
            scanf("%d %d %d", &row, &col, &amount);
            grid[row][col] = amount;
        }

        if(strcmp(command, "HOUR") == 0)
        {
            int eaten = progressHour(elephantList, numElephants, grid);
            printf("%d\n", eaten);
        }

        //scan before restarting
        scanf("%s", command);
    }

    for(int i = 0; i < numElephants; i++)
    {
        int row;
        int col;
        int * curRow = &row;
        int * curCol = &col;

        top(elephantList[i].memory, curRow, curCol);

        printf("%d %d\n", *curRow, *curCol);
    }

    for(int i = 0; i < 500; i++)
    {
        free(grid[i]);
        grid[i] = NULL;
    }

    free(grid);
    grid = NULL;

    for(int i = 0; i < numElephants; i++)
    {
        freeList(elephantList[i].memory.head);
    }

    free(elephantList);
    elephantList = NULL;

    return 0;
}