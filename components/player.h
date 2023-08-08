#ifndef PLAYER_H
#define PLAYER_H
#include "weapon.h"

typedef struct {
    char name[50];
    int health;
    int damage;
    int gold;
    Weapon weapon;
} Player;

extern Player createPlayer(const char *name);

extern void updateHealth(Player *player, int newHealth);

extern const char* getPlayerName(const Player *player);

extern int getPlayerHealth(const Player *player);

#endif
