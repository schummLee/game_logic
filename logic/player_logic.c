#include "player.h"
#include <string.h>

Player createPlayer(const char *name) {
    Player newPlayer;
    strcpy(newPlayer.name, name);
    newPlayer.health = 100;
    newPlayer.damage = 15;
    return newPlayer;
}

void updateHealth(Player *player, int newHealth) {
    player->health = newHealth;
}

const char* getPlayerName(const Player *player) {
    return player->name;
}

int getPlayerHealth(const Player *player) {
    return player->health;
}