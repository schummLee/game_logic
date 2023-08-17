#ifndef ARMOR_H
#define ARMOR_H

typedef struct {
    char name[50];
    int defense;
    int durability;
} Armor;

void initializeArmor(Armor *armor, const char *name, int defense, int durability);
void printArmor(const Armor *armor);

#endif 
