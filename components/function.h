#ifndef FUNCTION_H
#define FUNCTION_H
#include "player.h"
#include "enemy.h"
#include "effects.h"
typedef struct {
    char name[50]; int type;
} Function;

extern Function createFunction(const char* name,int type);

extern const char* getFunctionName(const Function *function);

extern void functionEffect(Function *function, Player *player);


extern void functionEffectToEnemy(Function *function,Enemy *enemy);

#endif
