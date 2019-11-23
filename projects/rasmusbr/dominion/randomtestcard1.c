#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main () {
    // Set random seed
    srand(time(NULL));
    int b;
    int numIterations = 100;

    for (int i = 0; i < numIterations; i++) {

        int inHand = rand() % 2;
        // Set up function inputs
        int randChoice = rand() % 2;
        struct gameState randGame;
        memset(&randGame, 0, sizeof(struct gameState));

        // Elements of gamestate
        randGame.whoseTurn = 0;
        randGame.handCount[0] = 5;
        randGame.discardCount[0] = 0;
        randGame.numActions = rand() % 5;
        randGame.coins = rand() % 10;
        randGame.numBuys = rand() % 4;

        // Set up player's hand
        if (inHand)  randGame.hand[0][0] = baron;
        else randGame.hand[0][0] = rand() % 26;
        randGame.hand[0][1] = rand() % 26;
        randGame.hand[0][2] = rand() % 26;
        randGame.hand[0][3] = rand() % 26;
        randGame.hand[0][4] = rand() % 26;

        // Save relevant variable before function call
        int preHandCount = randGame.handCount[0];
        int preDiscCount =  randGame.discardCount[0];
        int preNumActs = randGame.numActions;
        int preCoins = randGame.coins;

        // Call function
        b = cardBaron(randChoice, &randGame, whoseTurn(&randGame));
        
        // Compare expected v actual output
        if (preHandCount != randGame.handCount[0] + 1) printf ("Hand count incorrect!\n");
        if (preDiscCount != randGame.discardCount[0] - 1) printf ("Discard count incorrect!\n");
        if (preNumActs != randGame.numActions + 1) printf ("Action count incorrect!\n");
        if (preCoins != randGame.coins - 4 && randChoice) printf ("Coins incorrect!\n");
        if (preCoins != randGame.coins && !randChoice) printf ("Coins incorrect!\n");

    }

    return 0;
}