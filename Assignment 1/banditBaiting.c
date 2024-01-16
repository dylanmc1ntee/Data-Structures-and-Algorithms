#include<stdio.h>
#include<string.h>

typedef struct {
    
    int id;
    int previousFoodLevel;

} placement_t;

typedef struct {
    
    char locationName[20];
    placement_t existingPlacements[1];
    int numID;
    int totalFood;

} location_t;

int main()
{
    char name[20];
    int id, foodLevel;
    int end = 0;

    int length = 1;
    location_t *locations = (malloc(sizeof(location_t) * length));

    if(locations == NULL)
    {
        printf("Memory allocation FAILED.");
    }
    else
    {
        while(end == 0)
        {
            scanf("%s %d %d", name, &id, &foodLevel);

            if((!(strcmp(name, "END") == 0)) && (!(id == -1)) && (!(foodLevel == -1)))
            {
                int match = 0;

                for(int i = 0; i < length; i++)
                {
                    if(strcmp(name, locations[i].locationName) == 0)
                    {
                        match = 1;

                        for(int j = 0; j < locations[i].numID; j++)
                        {
                            if(locations[i].existingPlacements[j].id == id)
                            {
                                int changeInFood = locations[i].existingPlacements[j].previousFoodLevel - foodLevel;

                                if(changeInFood > 0)
                                {
                                    printf("%d\n", changeInFood);
                                    locations[i].existingPlacements[j].previousFoodLevel = foodLevel;
                                    locations[i].totalFood += changeInFood;
                                }
                                else
                                {
                                    printf("0\n");
                                    locations[i].existingPlacements[j].previousFoodLevel = foodLevel;
                                }
                            }
                            else
                            {

                            }
                        }
                    }
                    if(match == 0)
                    {
                        if((sizeof(locations) / sizeof(locations[0])) == length)
                        {
                            length++;
                            locations = realloc(locations, sizeof(locations) * length);
                            
                            
                        }
                    }
                    match = 0;
                }
            
            }
            else
            {
                for(int i = 0; i < length; i++)
                {
                    printf("%s %d\n", locations[i].locationName, locations[i].totalFood);
                }

                end = 1;
            }
        }
    }

    free(locations);
    locations = NULL;

    return 0;
}