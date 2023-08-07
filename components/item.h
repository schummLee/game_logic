#ifndef ITEM_H
#define ITEM_H
#include "function.h"

typedef struct {
    char name[50]; int quntity; int value; Function function;
} Item;

extern Item createItem(const char* name,int quntity,Function function);

extern void getItemName(const Item *item);

extern void createItemSpecial(const char* name,int quntity,int value);

extern void deleteItemSpecial(const char* name,int quntity,int value);

extern void useItem(const char* name,int quntity,Function function);

extern void dropItem(const char* name,int quntity,Function function);

#endif
