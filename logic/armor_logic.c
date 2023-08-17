#include <stdio.h>
#include "../components/armor.h"

void initializeArmor(Armor *armor, const char *name, int defense, int durability) {
    snprintf(armor->name, sizeof(armor->name), "%s", name);
    armor->defense = defense;
    armor->durability = durability;
}

void printArmor(const Armor *armor) {
    printf("Armor Name: %s\n", armor->name);
    printf("Defense: %d\n", armor->defense);
    printf("Durability: %d\n", armor->durability);
}
