#ifndef STORAGE_H
#define STORAGE_H

#include "item.h"

#define MAX_STORAGE_CAPACITY 50

typedef struct Item Item;

typedef struct {
    Item items[MAX_STORAGE_CAPACITY];
    int numItems;
    int maxCapacity;
} Storage;

extern Storage createStorage(Storage *storage, int capacity);

extern int addItemToStorage(Storage *storage, const Item *item);

extern int removeItemFromStorage(Storage *storage, const char *itemName);

extern void displayStorageContents(const Storage *storage);

#endif
