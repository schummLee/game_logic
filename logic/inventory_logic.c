#include "../components/inventory.h"
#include <stdio.h>
#include <string.h>

Inventory createInventory(Inventory *inventory) {
    inventory->numItems = 0;
    for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
        // Initialize item properties here
    }
}

int addItemToInventory(Inventory *inventory, const Item *item) {
    if (inventory->numItems >= MAX_INVENTORY_SIZE) {
        printf("Inventory is full. Cannot add more items.\n");
        return 0; 
    }

    inventory->items[inventory->numItems] = *item;
    inventory->numItems++;
    printf("Added '%s' to the inventory.\n", item->name);
    return 1; 
}

int removeItemFromInventory(Inventory *inventory, const char *itemName) {
    for (int i = 0; i < inventory->numItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            for (int j = i; j < inventory->numItems - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->numItems--;
            printf("Removed '%s' from the inventory.\n", itemName);
            return 1; 
        }
    }

    printf("Item '%s' not found in the inventory.\n", itemName);
    return 0; 
}

void displayInventory(const Inventory *inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->numItems; i++) {
        printf("- %s\n", inventory->items[i].name);
    }
}
