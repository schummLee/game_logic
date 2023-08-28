#ifndef BOSS_H
#define BOSS_H

#include "player.h" 

typedef struct Player Player;

typedef struct {
    char name[50];
    int health;
    int damage;
} Boss;

Boss createBoss(const char *name, int health, int damage);

void bossAttackPlayer(Boss *boss, Player *player);

const char* getBossName(const Boss *boss);

int getBossHealth(const Boss *boss);

int getBossDamage(const Boss *boss);

#endif
