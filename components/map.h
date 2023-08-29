#ifndef MAP_H
#define MAP_H
#define MAX_STRING_LENGTH 20
#include "../static/matrix_generator.h"
#include "player.h"

typedef struct {
    char type[MAX_STRING_LENGTH];
    int buff;
    int debuff;
} Map;

Map createMap(const char *type, int buff, int debuff);

const char* getMapName(const Map *map);

void applyMapEffects(Player *player, const Map *map);

#endif
