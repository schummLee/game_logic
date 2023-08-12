#include "storage.h"
#include <stdio.h>
#include <string.h>

Storage createStorage(Storage *storage, int capacity) {
    storage->numItems = 0;
    storage->maxCapacity = capacity;
    for (int i = 0; i < MAX_STORAGE_CAPACITY; i++) {
        // Initialize item properties here
    }
    return *storage;
}

int addItemToStorage(Storage *storage, const Item *item) {
    if (storage->numItems >= storage->maxCapacity) {
        printf("Storage is full. Cannot add more items.\n");
        return 0;
    }

    storage->items[storage->numItems] = *item;
    storage->numItems++;
    printf("Added '%s' to the storage.\n", item->name);
    return 1;
}

int removeItemFromStorage(Storage *storage, const char *itemName) {
    for (int i = 0; i < storage->numItems; i++) {
        if (strcmp(storage->items[i].name, itemName) == 0) {
            // Shift items to remove the target item
            for (int j = i; j < storage->numItems - 1; j++) {
                storage->items[j] = storage->items[j + 1];
            }
            storage->numItems--;
            printf("Removed '%s' from the storage.\n", itemName);
            return 1; 
        }
    }

    printf("Item '%s' not found in the storage.\n", itemName);
    return 0; 
}

void displayStorageContents(const Storage *storage) {
    printf("Storage Contents:\n");
    for (int i = 0; i < storage->numItems; i++) {
        printf("- %s\n", storage->items[i].name);
    }
}
