#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    
    int id;
    int previousFoodLevel;

} placement_t;

typedef struct {
    
    char locationName[20];
    //array of type placements_t inside of location struct
    placement_t * existingPlacements;
    int placementLength; //length of placement array
    int numID; //number of placements already in array
    int totalFood;

} location_t;

int main()
{
    //these variables hold the input from the user
    char name[20];
    int id, foodLevel;

    int locationsLength = 1;
    int numLocations = 0;
    //create main array of locations
    location_t* locations = (location_t *)(malloc(sizeof(location_t) * locationsLength)); 

    scanf("%s %d %d", name, &id, &foodLevel); //scans for user input

    //while user does not input "END -1 -1"
    while((strcmp(name, "END") != 0) && (id != -1) && (foodLevel != -1))
    {
        int locationIndex = -1;

        //for the length of locations
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

            //for the length of the placements array
            for(int i = 0; i < locations[locationIndex].placementLength; i++)
            {
                if(locations[locationIndex].existingPlacements[i].id == id)
                {
                    //if placement exists
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
                printf("New placement.\n");

                //if placement array is full
                if(locations[locationIndex].numID == locations[locationIndex].placementLength)
                {
                    //make placement array bigger
                    locations[locationIndex].existingPlacements = (placement_t*)(realloc(locations[locationIndex].existingPlacements, sizeof(placement_t) * (locations[locationIndex].placementLength + 1)));
                    locations[locationIndex].placementLength += 1;
                }
                
                //set the values for the newly created placement
                locations[locationIndex].existingPlacements[locations[locationIndex].numID].id = id;
                locations[locationIndex].existingPlacements[locations[locationIndex].numID].previousFoodLevel = foodLevel;

                locations[locationIndex].numID += 1;
            }
        }
        else
        {
            //location was not found
            printf("New placement.\n");

            //if location array is full
            if(numLocations == locationsLength)
            {
                //make location array bigger
                locations = (location_t*)(realloc(locations, (sizeof(location_t) * (locationsLength + 1))));
                locationsLength += 1;
            }

            //sets the values for newly created location
            strcpy(locations[numLocations].locationName, name);
            locations[numLocations].numID = 1;
            locations[numLocations].totalFood = 0;

            //create placement array for new location and assign all of the correct values
            locations[numLocations].existingPlacements = (placement_t*)(malloc(sizeof(placement_t) * locations[numLocations].numID));
            locations[numLocations].placementLength = 1;
            locations[numLocations].existingPlacements->id = id;
            locations[numLocations].existingPlacements->previousFoodLevel = foodLevel;

            numLocations += 1;
        }

        //scans for the next input
        scanf("%s %d %d", name, &id, &foodLevel);
    }

    //print all of the locations and how much food has been taken from there
    for(int i = 0; i < locationsLength; i++)
    {
        printf("%s %d\n", locations[i].locationName, locations[i].totalFood);
    }
    
    //free the placement array in each location
    for(int i = 0; i < locationsLength; i++)
    {
        free(locations[i].existingPlacements);
        locations[i].existingPlacements = NULL;
    }

    //free the location array
    free(locations);
    locations = NULL;
    
    return 0;
}