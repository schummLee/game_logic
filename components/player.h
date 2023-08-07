#ifndef PLAYER_H
#define PLAYER_H
#include "weapon.h"

typedef struct {
    char name[50];
    int health;
    int damage;
    Weapon weapon;
} Player;

Player createPlayer(const char *name);

void updateHealth(Player *player, int newHealth);

const char* getPlayerName(const Player *player);

int getPlayerHealth(const Player *player);

#endif
