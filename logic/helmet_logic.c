#include <stdio.h>
#include "../components/helmet.h"

void initializeHelmet(Helmet *helmet, const char *name, int defense, int durability, int visionBonus) {
    snprintf(helmet->name, sizeof(helmet->name), "%s", name);
    helmet->defense = defense;
    helmet->durability = durability;
    helmet->visionBonus = visionBonus;
}

void printHelmet(const Helmet *helmet) {
    printf("Helmet Name: %s\n", helmet->name);
    printf("Defense: %d\n", helmet->defense);
    printf("Durability: %d\n", helmet->durability);
    printf("Vision Bonus: %d\n", helmet->visionBonus);
}

