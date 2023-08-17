
#include <stdio.h>
#include "../components/stranger.h"

void combatWithStranger(Player *player, Stranger *stranger) {
    printf("You encounter a stranger and decide to engage in combat!\n");

    // Simulate combat logic
    while (player->health > 0 && stranger->health > 0) {
        // Player attacks stranger
        stranger->health -= player->damage;

        // Stranger attacks player
        player->health -= stranger->damage;
    }

    // Determine the result of the combat
    if (player->health > 0) {
        player->gold += stranger->goldReward;
        printf("Congratulations! You defeated the stranger and gained %d gold.\n", stranger->goldReward);
    } else {
        int goldLost = player->gold / 2; // Example: losing half of the gold
        player->gold -= goldLost;
        printf("You were defeated by the stranger and lost %d gold.\n", goldLost);
    }
}
