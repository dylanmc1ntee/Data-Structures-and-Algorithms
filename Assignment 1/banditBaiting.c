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
    int placementLength;
    int numID;
    int totalFood;

} location_t;

int main()
{
    char name[20];
    int id, foodLevel;

    int locationsLength = 1;
    int numLocations = 0;
    location_t* locations = (location_t *)(malloc(sizeof(location_t) * locationsLength));

    scanf("%s %d %d", name, &id, &foodLevel);

    while((strcmp(name, "END") != 0) && (id != -1) && (foodLevel != -1))
    {
        int locationIndex = -1;

        for(int i = 0; i < locationsLength; i++)
        {
            if(strcmp(locations[i].locationName, name) == 0)
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

            for(int i = 0; i < locations[locationIndex].placementLength; i++)
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
                    printf("0\n");
                }

                //set prevfoodlevel as new one
                locations[locationIndex].existingPlacements[positionIndex].previousFoodLevel = foodLevel;
            }
            else
            {
                //id not found
                //printf("1-");
                printf("New placement.\n");

                if(locations[locationIndex].numID == locations[locationIndex].placementLength)
                {
                    locations[locationIndex].existingPlacements = (placement_t*)(realloc(locations[locationIndex].existingPlacements, sizeof(placement_t) * (locations[locationIndex].placementLength + 1)));
                    locations[locationIndex].placementLength += 1;
                }

                locations[locationIndex].existingPlacements[locations[locationIndex].numID].id = id;
                locations[locationIndex].existingPlacements[locations[locationIndex].numID].previousFoodLevel = foodLevel;

                locations[locationIndex].numID += 1;
            }
        }
        else
        {
            //location was not found
            //printf("2-");
            printf("New placement.\n");
            if(numLocations == locationsLength)
            {
                locations = (location_t*)(realloc(locations, (sizeof(location_t) * (locationsLength + 1))));
                locationsLength += 1;
            }
            strcpy(locations[numLocations].locationName, name);
            locations[numLocations].numID = 1;
            locations[numLocations].totalFood = 0;

            locations[numLocations].existingPlacements = (placement_t*)(malloc(sizeof(placement_t) * locations[numLocations].numID));
            locations[numLocations].placementLength = 1;
            locations[numLocations].existingPlacements->id = id;
            locations[numLocations].existingPlacements->previousFoodLevel = foodLevel;

            numLocations += 1;
        }

        scanf("%s %d %d", name, &id, &foodLevel);
    }

    for(int i = 0; i < locationsLength; i++)
    {
        printf("%s %d\n", locations[i].locationName, locations[i].totalFood);
    }

    for(int i = 0; i < locationsLength; i++)
    {
        free(locations[i].existingPlacements);
        locations[i].existingPlacements = NULL;
    }

    free(locations);
    locations = NULL;
    
    return 0;
}