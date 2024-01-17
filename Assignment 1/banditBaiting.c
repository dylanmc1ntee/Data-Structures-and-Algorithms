#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    
    int id;
    int previousFoodLevel;

} placement_t;

typedef struct {
    
    char locationName[20];
    placement_t * existingPlacements;
    int numID;
    int totalFood;

} location_t;

int main()
{
    char name[20];
    int id, foodLevel;

    int locationsLength = 1;
    location_t* locations = (location_t *)(malloc(sizeof(location_t) * locationsLength));

    scanf("%s %d %d", name, &id, &foodLevel);

    while((strcmp(name, "END") != 0) && (id != -1) && (foodLevel != -1))
    {
        int locationIndex = -1;

        for(int i = 0; i < locationsLength; i++)
        {
            if(strcmp(locations[i].locationName, name))
            {
                //if location exists
                locationIndex = i;
                break;
            }
        }

        if(locationIndex != -1)
        {
            //location was found
            int positionIndex = -1;

            for(int i = 0; i < locations[locationIndex].numID; i++)
            {
                if(locations[locationIndex].existingPlacements[i].id == id)
                {
                    positionIndex = i;
                    break;
                }
            }

            if(positionIndex != -1)
            {
                //id was found
                int sum = locations[locationIndex].existingPlacements[positionIndex].previousFoodLevel - foodLevel;

                if(sum > 0)
                {
                    //add to total food taken
                    locations[locationIndex].totalFood += sum;
                    printf("%d\n", sum);
                }
                else
                {
                    printf("0");
                }

                //set prevfoodlevel as new one
                locations[locationIndex].existingPlacements[positionIndex].previousFoodLevel = foodLevel;
            }
            else
            {
                //id not found
                printf("New placement.\n");
            }
        }
        else
        {
            //location was not found
            printf("New placement.\n");
        }

        scanf("%s %d %d", name, &id, &foodLevel);
    }
    
    return 0;
}