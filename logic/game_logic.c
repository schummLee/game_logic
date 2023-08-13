#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../static/matrix_generator.h"  
#include "player_logic.c"  
#include "enemy_logic.c"  
#include "boss_logic.c"  
#include "weapon_logic.c"  
#include "map_logic.c" 
#include "item_logic.c"
#include "function_logic.c"
#include "effects.h" 
#include "shop_logic.c"
#include "home_logic.c"
#include "storage_logic.c"
#include "inventory_logic.c"
#include "npc_logic.c"
#define NUM_MAPS 5
#define NUM_ENEMIES 3
#define NUM_BOSSES 2
#define NUM_WEAPONS 3

void playerEncounterEnemy(Player *player, Enemy *enemy) {
    printf("Player encounters: %s\n", enemy->name);
    attackPlayer(enemy,player);
}

void playerEncounterBoss(Player *player, Boss *boss) {
    printf("Player encounters Boss: %s\n", boss->name);
    attackPlayer(boss,player);
}

void playerPickUpWeapon(Player *player, Weapon *weapon) {
    printf("Player picks up weapon: %s\n", weapon->name);
    player->weapon = createWeapon(weapon->name,weapon->damage);
}

void playerEncounterNpc(Player *player, Npc *npc, Boss *boss, Item *items, Weapon *weapons, int numItems, int numWeapons) {
    printf("Player encounters NPC: %s\n", npc->name);

    int interactionChoice = rand() % 3; 
    switch (interactionChoice) {
        case 0:
            printf("The NPC offers a chance to fight the boss!\n");
            attackPlayer(boss, player);
            break;
        case 1:
            if (numItems > 0) {
                int itemIndex = rand() % numItems;
                printf("The NPC offers to sell an item: %s\n", items[itemIndex].name);
                
            } else {
                printf("The NPC has no items to sell.\n");
            }
            break;
        case 2:
            int giveawayChoice = rand() % 2; 

            if (giveawayChoice == 0 && numWeapons > 0) {
                int weaponIndex = rand() % numWeapons;
                printf("The NPC gives you a weapon: %s\n", weapons[weaponIndex].name);
                // Implement logic for giving the weapon to the player
            } else if (numItems > 0) {
                int itemIndex = rand() % numItems;
                printf("The NPC gives you an item: %s\n", items[itemIndex].name);
                // Implement logic for giving the item to the player
            } else {
                printf("The NPC has nothing to give.\n");
            }
            break;
    }
}

void playerEnterShop(Player *player, Shop *shop) {
    printf("Player enters shop.\n");

    int timeOfDay = rand() % 3; 
    int goldSpent = rand() % 20 + 1;

    switch (timeOfDay) {
        case 0:
            printf("It's morning at the shop!\n");
            // Offer morning-specific items and weapons
            break;

        case 1:
            printf("It's afternoon at the shop!\n");
            // Offer afternoon-specific items and weapons
            break;

        case 2:
            printf("It's evening at the shop!\n");
            // Offer evening-specific items and weapons
            break;
    }

    printf("Player spends %d gold.\n", goldSpent);
    player->gold -= goldSpent;
}

void playerEnterHome(Player *player, Home *home,int itemIndex) {
    printf("Player enters home.\n");

    player->health += 50;
    printf("%s gains 50 health. Health: %d\n", player->name, player->health);

    printf("Opening the storage...\n");
    displayStorageContents(&(home->storage));

    printf("Enter the index of the item to switch (or -1 to cancel): ");

    if (itemIndex >= 0 && itemIndex < home->storage.numItems) {
        // Perform the item switch logic
        // implement logic for switching items and weapons here
        printf("You switched items.\n");
    } else if (itemIndex == -1) {
        printf("Item switching cancelled.\n");
    } else {
        printf("Invalid item index.\n");
    }
}

void playerEnterWildy(Player *player, Enemy *enemies, int numEnemies, Npc *npcs, int numNpcs, Item *items, int numItems, Weapon *weapons, int numWeapons) {
    printf("Player enters the wilderness.\n");

    int encounterChoice = rand() % 3; 

    switch (encounterChoice) {
        case 0:
            if (numEnemies > 0) {
                int enemyIndex = rand() % numEnemies;
                printf("Player encounters an enemy: %s\n", enemies[enemyIndex].name);
                attackPlayer(&(enemies[enemyIndex]), player);
            } else {
                printf("No enemies in the wilderness.\n");
            }
            break;
        case 1:
            if (numNpcs > 0) {
                int npcIndex = rand() % numNpcs;
                printf("Player encounters an NPC: %s\n", npcs[npcIndex].name);
                // Implement logic for interacting with the NPC
            } else {
                printf("No NPCs in the wilderness.\n");
            }
            break;
        case 2:
            int foundChoice = rand() % 2; 

            if (foundChoice == 0 && numItems > 0) {
                int itemIndex = rand() % numItems;
                playerPickupItem(player, items, numItems, weapons, numWeapons);
                printf("Player finds an item: %s\n", items[itemIndex].name);
                // Implement logic for adding the found item to the player's inventory
            } else if (numWeapons > 0) {
                int weaponIndex = rand() % numWeapons;
                playerPickupItem(player, items, numItems, weapons, numWeapons);
                printf("Player finds a weapon: %s\n", weapons[weaponIndex].name);
                // Implement logic for adding the found weapon to the player's inventory
            } else {
                printf("No items or weapons found.\n");
            }
            break;
    }
}

void playerPickupItem(Player *player, Item *items, int numItems, Weapon *weapons, int numWeapons) {
    printf("Player picks up an item from the map.\n");

    int pickupChoice = rand() % 2; 
    if (pickupChoice == 0 && numItems > 0) {
        int itemIndex = rand() % numItems;
        printf("Player picks up an item: %s\n", items[itemIndex].name);
        // Implement logic for adding the picked up item to the player's inventory
    } else if (numWeapons > 0) {
        int weaponIndex = rand() % numWeapons;
        printf("Player picks up a weapon: %s\n", weapons[weaponIndex].name);
        // Implement logic for adding the picked up weapon to the player's inventory
    } else {
        printf("No items or weapons to pick up.\n");
    }
}

void playGame(GameData *game) {
    printf("Starting the game!\n");

    for (int mapIndex = 0; mapIndex < NUM_MAPS; mapIndex++) {
        printf("\nEntering Map %d:\n", mapIndex + 1);
        printMatrix(game->map);

        if (rand() % 2 == 0) {
            int enemyIndex = rand() % NUM_ENEMIES;
            playerEncounterEnemy(&(game->player), &(game->enemy));
        }

        if (rand() % 4 == 0) {
            int bossIndex = rand() % NUM_BOSSES;
            playerEncounterBoss(&(game->player), &(game->boss));
        }

        if (rand() % 3 == 0) {
            int weaponIndex = rand() % NUM_WEAPONS;
            playerPickUpWeapon(&(game->player), &(game->weapon));
        }
    }

    if (game->player.health == 0) {
        printf("\nGame over!\n");
    }
}

