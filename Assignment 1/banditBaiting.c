#include<stdio.h>
#include<string.h>

typedef struct {
    
    int id;
    int previousFoodLevel;

} placement_t;

typedef struct {
    
    char locationName[20];
    placement_t existingPlacements[1];
    int totalFood;

} location_t;

int main()
{
    char name[20];
    int id, foodLevel;
    int end = 0;

    while(end == 0)
    {
        if((!(strcmp(name, "END") == 0) && (id == -1) && (foodLevel == -1)))
        {
            
        }
        else
        {
            end = 1;
        }
    }

    return 0;
}