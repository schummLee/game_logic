#ifndef SHOP_H
#define SHOP_H

#include "player.h"
#include "storage.h"
#include "item.h"
#include "daytime.h"

typedef struct Player Player;

typedef struct Storage Storage;

typedef struct Item Item;

typedef struct Daytime Daytime;

typedef struct {
   Storage storage;
   Item item; 
} Shop;

extern Shop createShop(Shop *shop);

extern void enterShop(Player *player, Shop *shop);

extern void buyItem(Player *player, Shop *shop, const char *itemName);

extern Item refreshItem(Item *item);

extern Shop showItem(Shop *shop, DayTime *dayTime);

#endif 
