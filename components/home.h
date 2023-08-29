#ifndef HOME_H
#define HOME_H

#include "player.h" 
#include "storage.h"

typedef struct {
   Storage storage;
} Home;

extern void enterHome(Player *player, Home *home);

extern void restAtHome(Player *player, Home *home);

#endif
