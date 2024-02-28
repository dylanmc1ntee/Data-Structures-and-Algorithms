#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numFruit 7
#define numBuy 3

void combination(char ** allFruit, char ** basket, int fruitIndex, int basketIndex){
    static int count = 1;
    
    // base case
    if(basketIndex == numBuy) { // filled basket
        printf("%d. ", count);
        for(int i = 0; i < numBuy; i++) {
            printf("%s ", basket[i]);
        }
        count++;
        printf("\n");
        return;
    }

    if(fruitIndex == numFruit) // out of fruit
    {
        return; // no more fruit :[ not enough to fill basket
    }

    basket[basketIndex] = allFruit[fruitIndex];
    combination(allFruit, basket, fruitIndex + 1, basketIndex + 1); // buy the fruit
    combination(allFruit, basket, fruitIndex + 1, basketIndex); // dont buy the fruit
}

int main() {
    char ** allFruit =(char **) malloc(sizeof(char*) * numFruit);
    char ** basket = (char **) malloc(sizeof(char*) * numBuy);

    allFruit[0] = "apple";
    allFruit[1] = "grape";
    allFruit[2] = "orange";
    allFruit[3] = "grapefruit";
    allFruit[4] = "kiwi";
    allFruit[5] = "tomato";
    allFruit[6] = "banana";

    combination(allFruit, basket, 0, 0);

    return 0;
}