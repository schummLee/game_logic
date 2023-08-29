#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

#define MAX_INVENTORY_SIZE 10

typedef struct {
    Item items[MAX_INVENTORY_SIZE];
    int numItems;
} Inventory;

extern Inventory createInventory(Inventory *inventory);

extern int addItemToInventory(Inventory *inventory, const Item *item);

extern int removeItemFromInventory(Inventory *inventory, const char *itemName);

extern void displayInventory(const Inventory *inventory);

#endif 
