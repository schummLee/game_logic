#include "function.h"
#include "effects.h"
#include <string.h>
#include <stdlib.h>

Function createFunction(const char* name,int type) {
    Function newFunction;
    strcpy(newFunction.name,name);
    newFunction.type = type;
    return newFunction;
}

const char* getFunctionName(const Function *function) {
    return function->name;
}

void functionEffect(Function *function, Player *player) {
    int types = function->type;

    switch(types) {
        case 1:
            function->type = REPLENISH;
            player->health += 20;
            break;

        case 2:
            function->type = WEAK;
            player->health -= 10;
            player->damage -= 5;
            break;

        case 3:
            function->type = HUNK;
            player->health += 50;
            break;

        case 4:
            function->type = POISON;
            player->health -= 20;
            break;

        case 5:
            function->type = GOD;
            player->health += 50;
            player->damage += 30;
            break;
        
    }
}

void functionEffectToEnemy(Function *function, Enemy *enemy) {
    int types = function->type;

    switch(types) {
        case 1:
            function->type = REPLENISH;
            enemy->health += 20;
            break;

        case 2:
            function->type = WEAK;
            enemy->health -= 10;
            enemy->damage -= 5;
            break;

        case 3:
            function->type = HUNK;
            enemy->health += 50;
            break;

        case 4:
            function->type = POISON;
            enemy->health -= 20;
            break;

        case 5:
            function->type = GOD;
            enemy->health += 50;
            enemy->damage += 30;
            break;
    }
}

