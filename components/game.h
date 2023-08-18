#ifndef GAME_H
#define GAME_H
#include "matrix_generator.h"  
#include "player.h"  
#include "enemy.h"  
#include "boss.h"  
#include "weapon.h"  
#include "map.h" 
#include "item.h"
#include "function.h"
#include "effects.h" 
#include "shop.h"
#include "home.h"
#include "storage.h"
#include "inventory.h"
#include "npc.h"
#include "game.h"
#include "effects.h"
#include "knight.h"
#include "stranger.h"
#include "helmet.h"
#include "armor.h"
#include "daytime.h"
#define MAX_STRING_LENGTH 100
#define MATRIX_SIZE 3

typedef struct {
    char name[MAX_STRING_LENGTH]; int health;
} Entity;

typedef struct {
    Player player; Enemy enemy; Boss boss; Weapon weapon; Map map; Item item;
    Function function; Npc npc; Item item; Home home; Shop shop; Storage storage;
    Inventory inventory; Knight knight; Armor armor; Helmet helmet;int temperature;
    Stranger stranger; DayTime daytime; 
    char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH];
} GameData;

typedef struct {
    const char *value; void (*function)();
} MatrixFunctionMapping;

typedef void (*FunctionWithPlayerParam)(Player *);
typedef void (*FunctionEnterColdArea)(Player *,Enemy *,Item *,int,DayTime);
typedef void (*FunctionEnterDesert)(Player *,Enemy *, int, Item *, int, DayTime);
typedef void (*FunctionCombatWithStranger)(Player *, Stranger *);
typedef void (*FunctionLightningStrikeAndRain)(Player *, Enemy *, int, Item *, int);
typedef void (*FunctionGetRandomItem)(Player *, Boss *, int, Item *, int);
typedef void (*FunctionExploreUnknownArea)(Player *, Weapon *, int, Armor *, int, Item *, int);
typedef void (*FunctionNightTimeEncounter)(Player *, Enemy *, Item *, int);
typedef void (*FunctionRecruitKnight)(Player *, Knight *);
typedef void (*FunctionHallOfFame)(Player *, Boss *, int);
typedef void (*FunctionEncounterEnemyWithHeavyArmor)(Player *, Enemy *, Armor *,int, Helmet *, int, Item * ,int);
typedef void (*FunctionDefeatMultiElementBoss)(Player *, Boss *);
typedef void (*FunctionSimulateRainfall)(Player *, Enemy *, int, Item *, int);
typedef void (*FunctionEnterProhibitedArea)(Player *, Enemy *);
typedef void (*FunctionEnterRainbowBridgeToHeaven)(Player *, Item *, int, Weapon *, int);
typedef void (*FunctionEncounterHugeAmountOfEnemies)(Player *, Enemy *, int , Item *, int, Weapon *, int);
typedef void (*FunctionCrossSwitchMatrices)(int, int);
typedef void (*FunctionEnterLightningStrikeArea)(Player *, Item *, int, Weapon *, int);
typedef void (*FunctionApplyTemperatureEffects)(Player *, Enemy *, Boss *, int);
typedef void (*FunctionPlayerEnterCampus)(Player *, Shop *, Item *, int, Weapon *, int);
typedef void (*FunctionPlayerOpenGift)(Player *,Boss *, int);
typedef void (*FunctionPlayerEncounterEnemy)(Player *,Enemy *);
typedef void (*FunctionPlayerEncounterBoss)(Player *, Boss *);
typedef void (*FunctionPlayerEncounterNpc)(Player *, Npc *, Boss *, Item *, Weapon *, Shop *, int, int);
typedef void (*FunctionPlayerEnterWildy)(Player *, Enemy *, int, Npc *, int, Item *, int, Weapon *, int);
typedef void (*FunctionPlayerPickupItem)(Player *, Item *, int, Weapon *, int);

extern void playerEncounterEnemy(Player *player, Enemy *enemy); 

extern void playerEncounterBoss(Player *player, Boss *boss); 

extern void playerPickUpWeapon(Player *player, Weapon *weapon); 

extern void playerEncounterNpc(
    Player *player, Npc *npc, 
    Boss *boss, Item *items, 
    Weapon *weapons, 
    Shop *shop,
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
