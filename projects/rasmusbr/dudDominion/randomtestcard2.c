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
    int m;
    int numIterations = 1000;

    for (int i = 0; i < numIterations; i++) {

        // Set up function inputs
        int randChoice = rand() % 2;
        struct gameState randGame;
        memset(&randGame, 0, sizeof(struct gameState));

        // Elements of gamestate
        randGame.numPlayers = rand() % 3 + 2;
        randGame.whoseTurn = 0;
        randGame.handCount[0] = 5;
        randGame.handCount[1] = 5;
        randGame.discardCount[0] = 0;
        randGame.coins = rand() % 10;
        randGame.numBuys = rand() % 4;

        // Set up player's hand
        randGame.hand[0][0] = minion;
        randGame.hand[0][1] = rand() % 26;
        randGame.hand[0][2] = rand() % 26;
        randGame.hand[0][3] = rand() % 26;
        randGame.hand[0][4] = rand() % 26;

        // Save relevant variable before function call
        int preHandCount = randGame.handCount[0];
        int preHandCountOther = randGame.handCount[1];
        int preDiscCount =  randGame.discardCount[0];
        int preNumActs = randGame.numActions;
        int preCoins = randGame.coins;

        // Call function
        m = minionCard(randChoice, &randGame, 0);
        
        // Compare expected v actual output
        if (!randChoice && randGame.handCount[0] != 4) printf ("Hand count incorrect!\n");
        if (!randChoice && preDiscCount != randGame.discardCount[0] - preHandCount) printf ("Discard count incorrect!\n");
        if (preNumActs != randGame.numActions) printf ("Action count incorrect!\n");
        if (randChoice && preCoins != randGame.coins - 2) printf ("Coins incorrect!\n");
        if (!randChoice && preCoins != randGame.coins) printf ("Coins incorrect!\n");
        if (!randChoice && preHandCountOther != 4) printf("Other player hand count incorrect!\n");
    }

    return 0;
}