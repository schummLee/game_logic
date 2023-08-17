#ifndef HELMET_H
#define HELMET_H

typedef struct {
    char name[50];
    int defense;
    int durability;
    int visionBonus;
} Helmet;

void initializeHelmet(Helmet *helmet, const char *name, int defense, int durability, int visionBonus);

void printHelmet(const Helmet *helmet);

#endif
