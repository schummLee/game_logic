#ifndef GAME_H
#define GAME_H
#include "../static/matrix_generator.h"  
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

// typedef void (*FunctionWithPlayerParam)(Player *);
// typedef void (*FunctionEnterColdArea)(Player *,Enemy *,Item *,int,DayTime);
// typedef void (*FunctionEnterDesert)(Player *,Enemy *, int, Item *, int, DayTime);
// typedef void (*FunctionCombatWithStranger)(Player *, Stranger *);
// typedef void (*FunctionLightningStrikeAndRain)(Player *, Enemy *, int, Item *, int);
// typedef void (*FunctionGetRandomItem)(Player *, Boss *, int, Item *, int);
// typedef void (*FunctionExploreUnknownArea)(Player *, Weapon *, int, Armor *, int, Item *, int);
// typedef void (*FunctionNightTimeEncounter)(Player *, Enemy *, Item *, int);
// typedef void (*FunctionRecruitKnight)(Player *, Knight *);
// typedef void (*FunctionHallOfFame)(Player *, Boss *, int);
// typedef void (*FunctionEncounterEnemyWithHeavyArmor)(Player *, Enemy *, Armor *,int, Helmet *, int, Item * ,int);
// typedef void (*FunctionDefeatMultiElementBoss)(Player *, Boss *);
// typedef void (*FunctionSimulateRainfall)(Player *, Enemy *, int, Item *, int);
// typedef void (*FunctionEnterProhibitedArea)(Player *, Enemy *);
// typedef void (*FunctionEnterRainbowBridgeToHeaven)(Player *, Item *, int, Weapon *, int);
// typedef void (*FunctionEncounterHugeAmountOfEnemies)(Player *, Enemy *, int , Item *, int, Weapon *, int);
// typedef void (*FunctionCrossSwitchMatrices)(int, int);
// typedef void (*FunctionEnterLightningStrikeArea)(Player *, Item *, int, Weapon *, int);
// typedef void (*FunctionApplyTemperatureEffects)(Player *, Enemy *, Boss *, int);
// typedef void (*FunctionPlayerEnterCampus)(Player *, Shop *, Item *, int, Weapon *, int);
// typedef void (*FunctionPlayerOpenGift)(Player *,Boss *, int);
// typedef void (*FunctionPlayerEncounterEnemy)(Player *,Enemy *);
// typedef void (*FunctionPlayerEncounterBoss)(Player *, Boss *);
// typedef void (*FunctionPlayerEncounterNpc)(Player *, Npc *, Boss *, Item *, Weapon *, Shop *, int, int);
// typedef void (*FunctionPlayerEnterWildy)(Player *, Enemy *, int, Npc *, int, Item *, int, Weapon *, int);
// typedef void (*FunctionPlayerPickupItem)(Player *, Item *, int, Weapon *, int);

typedef struct {
    char name[MAX_STRING_LENGTH]; int health;
} Entity;

typedef struct {
    Player player; Enemy enemy; Boss boss; Weapon weapon; Map map; Item item;
    Function function; Npc npc; Item item; Home home; Shop shop; Storage storage;
    Inventory inventory; Knight knight; Armor armor; Helmet helmet;int temperature;
    Stranger stranger; DayTime daytime; int numLoot; int someIntParam; int anotherIntParam;
    int yetAnotherIntParam;
    char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH];
} GameData;

typedef struct {
    const char *value; void (*function)(void *); void *params; } DynamicFunctionMapping;

typedef struct { Player *player; } FunctionWithPlayerParamParams;

typedef struct { Player *player; Enemy *enemy; Item *item; int numLoot; DayTime timeOfDay; } FunctionEnterColdAreaParams;

typedef struct { Player *player; Enemy *enemy; int someIntParam; Item *item; int anotherIntParam; DayTime timeOfDay; }
FunctionEnterDesertParams;

typedef struct { Player *player; Stranger *stranger; } FunctionCombatWithStrangerParams;

typedef struct { Player *player; Enemy *enemy; int someIntParam; Item *item; int anotherIntParam; }
FunctionLightningStrikeAndRainParams;

typedef struct { Player *player; Boss *boss; int someIntParam; Item *item; int anotherIntParam; }
FunctionGetRandomItemParams;

typedef struct { Player *player; Weapon *weapon; int someIntParam; Armor *armor; int anotherIntParam; Item *item;
    int yetAnotherIntParam; } FunctionExploreUnknownAreaParams;

typedef struct { Player *player; Enemy *enemy; Item *item; int numLoot; } FunctionNightTimeEncounterParams;

typedef struct { Player *player; Knight *knight; } FunctionRecruitKnightParams;

typedef struct { Player *player; Boss *boss; int someIntParam; } FunctionHallOfFameParams;

typedef struct { Player *player; Enemy *enemy; Armor *armor; int armorIntParam;
    Helmet *helmet; int helmetIntParam; Item *item; int itemIntParam;} 
FunctionEncounterEnemyWithHeavyArmorParams;

typedef struct { Player *player; Boss *boss; int someIntParam; } FunctionDefeatMultiElementBossParams;

typedef struct { Player *player; Enemy *enemy; int someIntParam; Item *item; int anotherIntParam; }
FunctionSimulateRainfallParams;

typedef struct { Player *player; Enemy *enemy; } FunctionEnterProhibitedAreaParams;

typedef struct { Player *player; Item *item; int someIntParam; Weapon *weapon; int weaponIntParam; }
FunctionEnterRainbowBridgeToHeavenParams;

typedef struct { Player *player; Enemy *enemy; int someIntParam;
    Item *item; int anotherIntParam; Weapon *weapon; int weaponIntParam; }
FunctionEncounterHugeAmountOfEnemiesParams;

typedef struct { int intParam1; int intParam2; } FunctionCrossSwitchMatricesParams;

typedef struct { Player *player; Item *item; int someIntParam; Weapon *weapon; int weaponIntParam; }
FunctionEnterLightningStrikeAreaParams;

typedef struct { Player *player; Enemy *enemy; Boss *boss; int someIntParam; }
FunctionApplyTemperatureEffectsParams;

typedef struct { Player *player; Shop *shop; Item *item; int itemIntParam; Weapon *weapon; int weaponIntParam; }
FunctionPlayerEnterCampusParams;

typedef struct { Player *player; Boss *boss; int someIntParam; } FunctionPlayerOpenGiftParams;

typedef struct { Player *player; Enemy *enemy; } FunctionPlayerEncounterEnemyParams;

typedef struct { Player *player; Boss *boss; } FunctionPlayerEncounterBossParams;

typedef struct { Player *player; Enemy *enemy; int someIntParam; Npc *npc;
    int npcIntParam; Item *item; Weapon *weapon; Shop *shop; int shopIntParam; int anotherIntParam; }
FunctionPlayerEncounterNpcParams;

typedef struct { Player *player; Enemy *enemy; int someIntParam; Npc *npc;
    int npcIntParam; Item *item; int itemIntParam; Weapon *weapon; int weaponIntParam; }
FunctionPlayerEnterWildyParams;

typedef struct { Player *player; Item *item; int itemIntParam; Weapon *weapon; int weaponIntParam; }
FunctionPlayerPickupItemParams;

extern void playerEncounterEnemy(Player *player, Enemy *enemy); 

extern void playerEncounterBoss(Player *player, Boss *boss); 

extern void playerPickUpWeapon(Player *player, Weapon *weapon); 

extern void playerEncounterNpc( Player *player, Npc *npc,  Boss *boss, Item *items, 
    Weapon *weapons,  Shop *shop, int numItems,  int numWeapons
);

extern void playerEnterHome(Player *player, Home *home, int itemIndex);

extern void playerEnterShop(Player *player, Shop *shop);

extern void playerEnterWildy( Player *player,  Enemy *enemies,  int numEnemies,  Npc *npcs, 
    int numNpcs,  Item *items,  int numItems,  Weapon *weapons,  int numWeapons
);

extern void playerPickupItem( Player *player, Item *items,  int numItems, Weapon *weapons,  int numWeapons);

extern void enterDesert(Player *player, Enemy *enemies, int numEnemies, Item *item, int numLoot, DayTime timeOfDay);

extern void combatWithStranger(Player *player, Stranger *stranger);

extern void acquireImmunityAndDebuff(Player *player);

extern void lightningStrikeAndRain(Player *player, Enemy *enemies, int numEnemies, Item *loot, int numLoot);

extern void getRandomInfo(Player *player, Boss *bosses, int numBosses, Item *item, int numLoot);

extern void exploreUnknownArea(Player *player, Weapon *weapons, int numWeapons, Armor *armors, int numArmors, Item *items, int numItems);

extern void nightTimeEncounter(Player *player, Enemy *enemy, Item *magicItems, int numMagicItems);

extern void recruitKnight(Player *player, Knight *knight);

extern void hallOfFame(Player *player, Boss *bosses, int numBosses);

extern void encounterEnemyWithHeavyArmor(Player *player, Enemy *enemy, Armor *armors, int numArmors, Helmet *helmets,     int numHelmets, Item *defenseItems, int numDefenseItems);

extern void defeatMultiElementBoss(Player *player, Boss *boss);

extern void simulateRainfall(Player *player, Enemy *enemies, int numEnemies, Item *waterItems, int numWaterItems);

extern void enterProhibitedArea(Player *player, Enemy *enemy);

extern void increaseDamageRandomPercent(Player *player);

extern void enterRainbowBridgeToHeaven(Player *player, Item *heavenItems, int numHeavenItems, Weapon *heavenWeapons,     int numHeavenWeapons);

extern void encounterHugeAmountOfEnemies(Player *player, Enemy *enemies, int numEnemies, Item *items, int numItems, W    eapon *weapons, int numWeapons);

extern void crossSwitchMatrices(int matrix1[3], int matrix2[5]);

extern void enterLightningStrikeArea(Player *player, Item *lightningItems, int numLightningItems, Weapon *lightningWe    apons, int numLightningWeapons);

extern void enterForest(Player *player);

extern void powerOfHeaven(Player *player);

extern void applyTemperatureEffects(Player *player, Enemy *enemies, Boss *boss, int temperature);

extern void playerEnterCampus(Player *player, Shop *shop, Item *enchantedItems, int numEnchantedItems, Weapon *enchan    tedWeapons, int numEnchantedWeapons);

extern void playerRest(Player *player);

extern void playerOpenGift(Player *player, Boss *boss, int explorationCompleted);

extern void playerEncounterEnemy(Player *player, Enemy *enemy);

extern void playerEncounterBoss(Player *player, Boss *boss);

extern void playerPickUpWeapon(Player *player, Weapon *weapon);

extern void playerEncounterNpc(Player *player, Npc *npc, Boss *boss, Item *items, Weapon *weapons, Shop *shop, int nu    mItems, int numWeapons);

extern void playerEnterShop(Player *player, Shop *shop);

extern void playerEnterHome(Player *player, Home *home,int itemIndex);

extern void playerEnterWildy(Player *player, Enemy *enemies, int numEnemies, Npc *npcs, int numNpcs, Item *items, int     numItems, Weapon *weapons, int numWeapons);

extern void playerPickupItem(Player *player, Item *items, int numItems, Weapon *weapons, int numWeapons);

extern void playGame(GameData *game);

#endif 
