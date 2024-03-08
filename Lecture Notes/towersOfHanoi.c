#include<stdio.h>
#include<stdlib.h>

int moves(int disks, char * src, char * dest, char * aux)
{
    if(disks == 0)
    {
        return 0;
    }

    int result = 0;

    result += moves(disks - 1, src, aux, dest);

    printf("Move Disk %d from %s to %s\n", disks, src, dest);
    result++;

    result += moves(disks - 1, aux, dest, src);

    return result;
}

#define SIZE 3

int main()
{
    printf("It takes %d moves to move %d disks.\n", moves(SIZE, "East", "West", "Center"), SIZE);

    return 0;
}