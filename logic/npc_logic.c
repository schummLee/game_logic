#include "npc.h"
#include <string.h>

NPC createNPC(const char *name, int health, int damage) {
    NPC newNPC;
    strcpy(newNPC.name, name);
    newNPC.health = health;
    newNPC.damage = damage;
    return newNPC;
}

void interactWithNPC(NPC *npc) {
 // write login here
}

const char* getNPCName(const NPC *npc) {
    return npc->name;
}

int getNPCHealth(const NPC *npc) {
    return npc->health;
}

int getNPCDamage(const NPC *npc) {
    return npc->damage;
}
