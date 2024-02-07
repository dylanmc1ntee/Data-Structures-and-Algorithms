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

//creates new node for linked list
Node * createNode(int row, int col)
{
    Node * ret;
    ret = (Node *) malloc(sizeof(Node));
    ret->r = row;
    ret->c = col;
    ret->next = NULL;
    return ret;
}

//pretty much insert head function
void push(Stack * stack, int row, int col)
{
    Node * newHead = (Node *) malloc(sizeof(Node));
    newHead->r = row;
    newHead->c = col;
    newHead->next = stack->head;
    stack->head = newHead;
}

//pretty much remove head function
void pop(Stack * stack)
{
    Node * tmp;
    if(stack->head == NULL) return;
    tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}

/*
you pass a pointer to a row and col int, this function changes
those int values to the current row and col of the elephant
*/
void top(Stack stack, int * rowPtr, int * colPtr)
{
    //if not empty
    if(stack.head != NULL)
    {
        *rowPtr = stack.head->r;
        *colPtr = stack.head->c;
    }
}

//adds bait to the given row and col
void addBait(int ** grid, int row, int col, int amount)
{
    grid[row][col] = amount;
}

//returns the amount of bait at given spot and sets to 0
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

    //gets current position
    top(elephant->memory, curRow, curCol);

    //if not against the wall
    if(*curRow != 499 && grid[*curRow + 1][*curCol] > 0)
    {
        //gets amount of bait to the right
        right = grid[*curRow + 1][*curCol];
    }
    //if not against the wall
    else if(*curRow != 0 && grid[*curRow - 1][*curCol] > 0)
    {
        //gets amount of bait to the left
        left = grid[*curRow - 1][*curCol];
    }
    //if not against the wall
    else if(*curCol != 499 && grid[*curRow][*curCol + 1] > 0)
    {
        //gets amount of bait below
        down = grid[*curRow][*curCol + 1];
    }
    //if not against the wall
    else if(*curCol != 0 && grid[*curRow][*curCol - 1] > 0)
    {
        //gets amount of bait above
        up = grid[*curRow][*curCol - 1];
    }
    else
    {
        //nothing
    }

    //if there is no bait around
    if(up == 0 && down == 0 && left == 0 && right == 0)
    {
        //if its not in origional position
        if(elephant->memory.head->next != NULL)
        {
            //move to previous position
            pop(&elephant->memory);
        }
    }
    //if bait is found
    else
    {
        //if the most bait is up
        if(up > down && up > left && up > right)
        {
            //move up
            push(&elephant->memory, *curRow, *curCol - 1);
        }
        //if the most bait is down
        if(down > up && down > left && down > right)
        {
            //move down
            push(&elephant->memory, *curRow, *curCol + 1);
        }
        //if the most bait is to the left
        if(left > down && left > up && left > right)
        {
            //move left
            push(&elephant->memory, *curRow - 1, *curCol);
        }
        //if the most bait is to the right
        if(right > down && right > left && right > up)
        {
            //move right
            push(&elephant->memory, *curRow + 1, *curCol);
        }
    }
}

//simulates 1 hour
int progressHour(Elephant * elephant, int numElephants, int ** grid)
{
    int numEaten = 0;

    //for every elephant
    for(int i = 0; i < numElephants; i++)
    {
        int row;
        int col;
        int* curRow = &row;
        int* curCol = &col;

        //get current position
        top(elephant[i].memory, curRow, curCol);

        //if there is food
        if(grid[*curRow][*curCol] > 0)
        {
            //eat
            numEaten += eatBait(grid, row, col);
        }
        //if no food
        else
        {
            //move
            move(&elephant[i], grid);
        }
    }

    //for number of elephants
    for(int i = 0; i < numElephants; i++)
    {
        int row;
        int col;
        int* curRow = &row;
        int* curCol = &col;

        //get current position
        top(elephant[i].memory, curRow, curCol);

        //if there is food
        if(grid[*curRow][*curCol] > 0)
        {
            //eat
            numEaten += eatBait(grid, row, col);
        }
    }

    //return total amount of food eaten
    return numEaten;
}

//frees dynamic memory in list
void freeList(Node * head)
{
    Node * tmp;

    //not empty
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

    //prints final position
    for(int i = 0; i < numElephants; i++)
    {
        int row;
        int col;
        int * curRow = &row;
        int * curCol = &col;

        top(elephantList[i].memory, curRow, curCol);

        printf("%d %d\n", *curRow, *curCol);
    }

    //frees columns in grid
    for(int i = 0; i < 500; i++)
    {
        free(grid[i]);
        grid[i] = NULL;
    }

    //frees rows in grid
    free(grid);
    grid = NULL;

    //free linked lists in each elephant
    for(int i = 0; i < numElephants; i++)
    {
        freeList(elephantList[i].memory.head);
    }

    //free elephants
    free(elephantList);
    elephantList = NULL;

    return 0;
}