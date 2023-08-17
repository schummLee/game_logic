#ifndef ENEMY_H
#define ENEMY_H

typedef struct {
    char name[50]; int health; int damage; int buffAmount; int poisonChance; int magicLootChance;
} Enemy;

Enemy createEnemy(const char *name, int health, int damage);

void attackPlayer(Enemy *enemy, Player *player);

const char* getEnemyName(const Enemy *enemy);

int getEnemyHealth(const Enemy *enemy);

int getEnemyDamage(const Enemy *enemy);

#endif
