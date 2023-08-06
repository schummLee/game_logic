#include "enemy.h"
#include "player.h"
#include <string.h>

Enemy createEnemy(const char *name, int health, int damage) {
    Enemy newEnemy;
    strcpy(newEnemy.name, name);
    newEnemy.health = health;
    newEnemy.damage = damage;
    return newEnemy;
}

void attackPlayer(Enemy *enemy, Player *player) {
    int playerHealth = getPlayerHealth(player);
    int damage = getEnemyDamage(enemy);

    updatePlayerHealth(player, playerHealth - damage);
}

const char* getEnemyName(const Enemy *enemy) {
    return enemy->name;
}

int getEnemyHealth(const Enemy *enemy) {
    return enemy->health;
}

int getEnemyDamage(const Enemy *enemy) {
    return enemy->damage;
}
