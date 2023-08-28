#include "../components/shop.h"
#include "../components/player.h"
#include "../components/item.h"
#include "../components/daytime.h"
#include <stdio.h>
#include <string.h>
#include "daytime.h"

Shop createShop(Shop *shop) {
    createStorage(&(shop->storage), MAX_STORAGE_CAPACITY);
    initializeItem(&(shop->item), "Health Potion");
    return *shop;
}

void enterShop(Player *player, Shop *shop) {
    printf("Welcome to the shop!\n");
    // Additional shop-related logic could go here
}

void buyItem(Player *player, Shop *shop, const char *itemName) {
    Item *itemToBuy = NULL;
    for (int i = 0; i < shop->storage.numItems; i++) {
        if (strcmp(shop->storage.items[i].name, itemName) == 0) {
            itemToBuy = &(shop->storage.items[i]);
            break;
        }
    }

    if (itemToBuy == NULL) {
        printf("Item '%s' is not available for purchase.\n", itemName);
        return;
    }

    if (player->gold >= itemToBuy->value) {
        if (addItemToStorage(&(player->inventory), itemToBuy)) {
            player->gold -= itemToBuy->value;
            removeItemFromStorage(&(shop->storage), itemName);
            printf("You bought '%s'!\n", itemName);
        } else {
            printf("Your inventory is full. Cannot buy '%s'.\n", itemName);
        }
    } else {
        printf("You don't have enough gold to buy '%s'.\n", itemName);
    }
}

Item refreshItem(Item *item) { return *item; }

Shop showItem(Shop *shop, DayTime *dayTime) {
    if (*dayTime == MORNING || *dayTime == AFTERNOON) {
        shop->item = refreshItem(&(shop->item));
    }
    else if (*dayTime == MORNING || *dayTime == AFTERNOON) {
        shop->item = refreshItem(&(shop->item));
    }
    else if (*dayTime == EVENING || *dayTime == NIGHT) {
        shop->item = refreshItem(&(shop->item));
    }

