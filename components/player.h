#ifndef PLAYER_H
#define PLAYER_H
#include "weapon.h"
#include "enemy.h"
#include "boss.h"
#include "shop.h"
#include "npc.h"
#include "inventory.h"

typedef struct {
    char name[50]; int health; int maxHealth; int damage;
    int gold; int debuffImmunity; int encounterChance;
    Weapon weapon; Inventory inventory;
} Player;

extern Player createPlayer(const char *name);

extern void updateHealth(Player *player, int newHealth);

extern const char* getPlayerName(const Player *player);

extern int getPlayerHealth(const Player *player);

extern int getPlayerGold(const Player *player);

extern void attackEnemy(Player *player, Enemy *enemy);

extern void attackBoss(Player *player, Boss *boss);

extern void spendGold(Player *player, Shop *shop, Npc *npc);

#endif
