#include "player.h"
#ifndef STRANGER_H
#define STRANGER_H

typedef struct Stranger {
    int health;
    int damage;
    int goldReward;
} Stranger;

void combatWithStranger(Player *player, Stranger *stranger);

#endif 
