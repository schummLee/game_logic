#include "boss.h"
#include <string.h>

Boss createBoss(const char *name, int health, int damage) {
    Boss newBoss;
    strcpy(newBoss.name, name);
    newBoss.health = health;
    newBoss.damage = damage;
    return newBoss;
}

void attackPlayer(Boss *boss, Player *player) {
    int playerHealth = getPlayerHealth(player);
    int damage = getBossDamage(boss);
    updatePlayerHealth(player, playerHealth - damage);
}

const char* getBossName(const Boss *boss) {
    return boss->name;
}

int getBossHealth(const Boss *boss) {
    return boss->health;
}

int getBossDamage(const Boss *boss) {
    return boss->damage;
}
