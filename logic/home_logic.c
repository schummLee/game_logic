#include <stdio.h>
#include "../components/home.h"
#include "../components/player.h"

Home createHome() {
    Home newHome;
    // Initialize the storage
    newHome.storage = createStorage(&newHome.storage, MAX_STORAGE_CAPACITY);
    return newHome;
}

void enterHome(Player *player, Home *home) {
    printf("%s enters their home.\n", player->name);

    int itemIndex;
    printf("Enter the index of the item to switch (or -1 to cancel): ");
    scanf("%d", &itemIndex);

    if (itemIndex >= 0 && itemIndex < home->storage.numItems) {
        // Perform the item switch logic
        Item itemToSwitch = home->storage.items[itemIndex];
        addItemToInventory(&(player->inventory), &itemToSwitch);
        removeItemFromStorage(&(home->storage), itemToSwitch.name);
        printf("You switched items.\n");
    } else if (itemIndex == -1) {
        printf("Item switching cancelled.\n");
    } else {
        printf("Invalid item index.\n");
    }
}

void displayHomeStorage(const Home *home) {
    printf("Home Storage Contents:\n");
    displayStorageContents(&(home->storage));
}
