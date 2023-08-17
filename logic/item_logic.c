#include "item.h"
#include "function.h"
#include "player.h"
#include <string.h>
#include <stdlib.h>

Item createItem(const char* name,int quntity,Function *function) {
    Item newItem;
    strcpy(newItem.name, name);
    newItem.quntity = quntity;
    newItem.function = *function;
    return newItem;
}

void getItemName(const Item *item) {
    return item->name;
}

Item createItemSpeical(const char* name,int quntity,int value) {
    Item newSpeicalItem;
    strcpy(newSpeicalItem.name, name);
    newSpeicalItem.quntity = quntity;
    newSpeicalItem.value = value;
    return newSpeicalItem;       
}

void useItem(const char* name,int quntity,Function *function,Player *player) {
    quntity -= 1; 
    functionEffect(function,player);
}

void useItemOnEnemy(const char* name,int quntity,Function *function,Enemy *enemy) {
    quntity -= 1; 
    functionEffectToEnemy(function,enemy);
}