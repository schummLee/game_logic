#include <stdio.h>
#include "../components/knight.h"
#include "../components/armor.h"
#include "../components/helmet.h"

void initializeKnight(Knight *knight, const char *name, int health, const Armor *armor, const Helmet *helmet,int buyCost) {
    snprintf(knight->name, sizeof(knight->name), "%s", name);
    knight->health = health;
    knight->armor = *armor; 
    knight->helmet = *helmet;
    knight->buyCost = buyCost;
}

void printKnight(const Knight *knight) {
    printf("Knight Name: %s\n", knight->name);
    printf("Health: %d\n", knight->health);
    printf("Armor Details:\n");
    printArmor(&knight->armor);
    printf("Helmet Details:\n");
    printHelmet(&knight->helmet);
}
