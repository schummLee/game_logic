#ifndef NPC_H
#define NPC_H

typedef struct {
    char name[50];
    int health;
    int damage;
} Npc;

extern Npc createNPC(const char *name, int health, int damage);

extern void interactWithNPC(Npc *npc);

extern const char* getNPCName(const Npc *npc);

extern int getNPCHealth(const Npc *npc);

extern int getNPCDamage(const Npc *npc);

#endif
