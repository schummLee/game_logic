#ifndef ITEM_H
#define ITEM_H
#include "function.h"

typedef struct {
    char name[50]; int quntity; int value; Function function; int poisonResistance;
    int magicResistance;
} Item;

extern Item createItem(const char* name,int quntity,Function *function);

extern void getItemName(const Item *item);

extern Item createItemSpecial(const char* name,int quntity,int value);

extern void deleteItemSpecial(const char* name,int quntity,int value);

extern void useItem(const char* name,int quntity,Function *function,Player *player);

extern void useItemOnEnemy(const char* name,int quntity,Function *function,Enemy *enemy);

extern void dropItem(const char* name,int quntity,Function function,Player *player);

#endif
