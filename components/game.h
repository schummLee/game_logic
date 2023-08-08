#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "weapon.h"
#include "map.h"
#include "item.h"
#include "npc.h"
#define MAX_STRING_LENGTH 100
#define MATRIX_SIZE 5

typedef struct {
    Player player; Enemy enemy; Boss boss; Weapon weapon; Map map; Item item;
    char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH];
} GameData;
extern void playerEncounterEnemy(Player *player, Enemy *enemy); 

extern void playerEncounterBoss(Player *player, Boss *boss); 

extern void playerPickUpWeapon(Player *player, Weapon *weapon); 

extern void playerEncounterNpc(
    Player *player, Npc *npc, 
    Boss *boss, Item *items, 
    Weapon *weapons, 
    int numItems, 
    int numWeapons
);

extern void playerEnterHome(Player *player, Home *home, int itemIndex);

extern void playerEnterShop(Player *player, Shop *shop);

extern void playerEnterWildy(
    Player *player,  Enemy *enemies, 
    int numEnemies,  Npc *npcs, 
    int numNpcs,  Item *items, 
    int numItems,  Weapon *weapons, 
    int numWeapons
);

extern void playerPickupItem(
    Player *player, Item *items, 
    int numItems, Weapon *weapons, 
    int numWeapons);

extern void playGame(GameData *game);

#endif 
