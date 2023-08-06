#ifndef NPC_H
#define NPC_H

typedef struct {
    char name[50];
    int health;
    int damage;
} NPC;

NPC createNPC(const char *name, int health, int damage);

void interactWithNPC(NPC *npc);

const char* getNPCName(const NPC *npc);

int getNPCHealth(const NPC *npc);

int getNPCDamage(const NPC *npc);

#endif
