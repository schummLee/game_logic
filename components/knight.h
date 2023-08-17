#ifndef KNIGHT_H
#define KNIGHT_H

#include "armor.h" 
#include "helmet.h"

typedef struct {
    char name[50]; int health; Armor armor;  Helmet helmet; 
} Knight;

void initializeKnight(Knight *knight, const char *name, int health, const Armor *armor, const Helmet *helmet);

void printKnight(const Knight *knight);

#endif
