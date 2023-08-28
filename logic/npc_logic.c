#include "../components/npc.h"
#include <string.h>

Npc createNPC(const char *name, int health, int damage) {
    Npc newNPC;
    strcpy(newNPC.name, name);
    newNPC.health = health;
    newNPC.damage = damage;
    return newNPC;
}

void interactWithNPC(Npc *npc) {
 // write login here
}

const char* getNPCName(const Npc *npc) {
    return npc->name;
}

int getNPCHealth(const Npc *npc) {
    return npc->health;
}

int getNPCDamage(const Npc *npc) {
    return npc->damage;
}
