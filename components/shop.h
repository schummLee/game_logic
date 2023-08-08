#ifndef SHOP_H
#define SHOP_H

#include "player.h"
#include "storage.h"

typedef struct {
   Storage storage;
    
} Shop;

extern void enterShop(Player *player, Shop *shop);

extern void buyItem(Player *player, Shop *shop, const char *itemName);

#endif 
