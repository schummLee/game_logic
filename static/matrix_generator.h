#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#define MATRIX_SIZE 3
#define MAX_STRING_LENGTH 20
#include "../components/player.h"
#include "../components/enemy.h"
#include "../components/boss.h"
#include "../components/weapon.h"
#include "../components/map.h"
#include "../components/game.h"

typedef struct { char name[MAX_STRING_LENGTH]; int health; } Entity;

typedef struct {
    Player player; Enemy enemy; Boss boss; Weapon weapon; Map map;
    char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH];
} GameData;

void generateRandomMatrix(char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH]);
void playerEncounterEnemy(Player *player, Enemy *enemy);
void playerEncounterBoss(Player *player, Boss *boss);
void playerPickUpWeapon(Player *player, Weapon *weapon);
void playGame(GameData *game);

#endif
