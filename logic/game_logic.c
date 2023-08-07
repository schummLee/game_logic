#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matrix_generator.h"  
#include "player.h"  
#include "enemy.h"  
#include "boss.h"  
#include "weapon.h"  
#include "map.h"  
#define NUM_MAPS 5
#define NUM_ENEMIES 3
#define NUM_BOSSES 2
#define NUM_WEAPONS 3

typedef struct {
    char name[MAX_STRING_LENGTH]; int health;
} Entity;

typedef struct {
    Player player; Enemy enemy; Boss boss; Weapon weapon; Map map;
    char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH];
} GameData;

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

void playGame(GameData *game) {
    printf("Starting the game!\n");

    for (int mapIndex = 0; mapIndex < NUM_MAPS; mapIndex++) {
        printf("\nEntering Map %d:\n", mapIndex + 1);
        generateRandomMatrix(game->matrix); 
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

    printf("\nGame over!\n");
}

