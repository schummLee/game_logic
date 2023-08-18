#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../static/matrix_generator.h"  
#include "player_logic.c"  
#include "enemy_logic.c"  
#include "boss_logic.c"  
#include "weapon_logic.c"  
#include "map_logic.c" 
#include "item_logic.c"
#include "function_logic.c"
#include "effects.h" 
#include "shop_logic.c"
#include "home_logic.c"
#include "storage_logic.c"
#include "inventory_logic.c"
#include "npc_logic.c"
#include "stranger_logic.c"
#include "armor_logic.c"
#include "knight_logic.c"
#define NUM_MAPS 5
#define NUM_ENEMIES 3
#define NUM_BOSSES 2
#define NUM_WEAPONS 3

void enterColdArea(Player *player, Enemy *enemy, Item *item, int numLoot, DayTime timeOfDay) {
    printf("You enter a bitterly cold area, where the chilling winds pose challenges!\n");

    // Double the damage for both player and enemy
    player->damage *= 2;
    enemy->damage *= 2;

    printf("Your damage and the enemy's damage have doubled due to the extreme cold.\n");

    // Check if it's still night
    int isNight = (timeOfDay == NIGHT);

    if (isNight) {
        printf("Night falls and the cold becomes unbearable.\n");
        printf("You couldn't survive the night and meet your demise.\n");
        player->health = 0; // Player dies
    } else {
        printf("You manage to endure the cold night.\n");

        printf("You encounter an enemy: %s\n", enemy->name);
        // Implement player-enemy combat logic here
        // player->health -= enemy->damage;
        // enemy->health -= player->damage

        // Simulate dropping snow-related loot
        if (numLoot > 0) {
            int lootIndex = rand() % numLoot;
            printf("You find a snow-related loot: %s\n", item[lootIndex].name);
            // Implement logic to add the loot to the player's inventory
        }
    }
}

void enterDesert(Player *player, Enemy *enemies, int numEnemies, Item *item, int numLoot, DayTime timeOfDay) {
    printf("You enter the desert, where the harsh conditions pose challenges!\n");

    // Apply effects of the desert based on time of day
    player->health -= 10; // Health decreases
    player->damage += 5;  // Damage increases

    printf("Your health decreases due to the harsh desert conditions.\n");
    printf("Your damage increases as you adapt to the environment.\n");

    // Check if it's night
    int isNight = (timeOfDay == NIGHT);

    if (isNight) {
        printf("Night falls and the desert becomes even more treacherous.\n");
        printf("You couldn't survive the night and meet your demise.\n");
        player->health = 0; // Player dies
    } else {
        printf("You manage to survive the night in the desert.\n");

        // Simulate encounters with enemies
        if (numEnemies > 0) {
            int enemyIndex = rand() % numEnemies;
            printf("You encounter an enemy: %s\n", enemies[enemyIndex].name);
            // Implement player-enemy combat logic here
            // player->health -= enemies[enemyIndex].damage;
            // enemies[enemyIndex].health -= player->damage;
        }

        // Simulate dropping sand-related loot
        if (numLoot > 0) {
            int lootIndex = rand() % numLoot;
            printf("You find a sand-related loot: %s\n", item[lootIndex].name);
            // Implement logic to add the loot to the player's inventory
        }
    }
}

void combatWithStranger(Player *player, Stranger *stranger) {
    printf("You encounter a stranger and decide to engage in combat!\n");

    // Simulate combat logic
    while (player->health > 0 && stranger->health > 0) {
        // Player attacks stranger
        stranger->health -= player->damage;

        // Stranger attacks player
        player->health -= stranger->damage;
    }

    // Determine the result of the combat
    if (player->health > 0) {
        player->gold += stranger->goldReward;
        printf("Congratulations! You defeated the stranger and gained %d gold.\n", stranger->goldReward);
    } else {
        int goldLost = player->gold / 2; // Example: losing half of the gold
        player->gold -= goldLost;
        printf("You were defeated by the stranger and lost %d gold.\n", goldLost);
    }
}

void acquireImmunityAndDebuff(Player *player) {
    printf("You acquire immunity to all debuffs!\n");

    player->debuffImmunity = 1; // Immune to debuffs

    double damageDecreasePercentage = (rand() % 26 + 5) / 100.0; // Random 5% to 30%
    int damageDecreaseAmount = (int)(player->damage * damageDecreasePercentage);

    player->damage -= damageDecreaseAmount;

    printf("Your damage has been decreased by %.2f%% due to the immunity.\n", damageDecreasePercentage * 100);
}


void lightningStrikeAndRain(Player *player, Enemy *enemies, int numEnemies, Item *loot, int numLoot) {
    printf("A lightning strike occurs and heavy rain begins!\n");

    // Apply debuffs to the player
    player->damage -= 10; // Example debuff

    // Apply buffs to enemies
    for (int i = 0; i < numEnemies; i++) {
        enemies[i].damage += enemies[i].buffAmount; // Example buff
    }

    printf("The player's damage is decreased by 10 due to rain and lightning.\n");

    for (int i = 0; i < numEnemies; i++) {
        printf("Enemy %s's damage is increased by %d due to rain and lightning.\n",
               enemies[i].name, enemies[i].buffAmount);
    }

    // Loot related to lightning and water
    if (numLoot > 0) {
        int lootIndex = rand() % numLoot;
        printf("You find a special loot: %s\n", loot[lootIndex].name);
        // Implement logic to add the loot to the player's inventory
    }
}

void getRandomInfo(Player *player, Boss *bosses, int numBosses, Item *item, int numLoot) {
    printf("You learn some random information about loot and bosses!\n");

    // Randomly determine whether to provide information about loot or bosses
    int infoType = rand() % 2; // 0: Loot, 1: Boss

    switch (infoType) {
        case 0:
            if (numLoot > 0) {
                int lootIndex = rand() % numLoot;
                printf("You learn about loot: %s\n", item[lootIndex].name);
                // You can provide additional details about the loot here
            }
            break;

        case 1:
            if (numBosses > 0) {
                int bossIndex = rand() % numBosses;
                printf("You learn about a boss: %s\n", bosses[bossIndex].name);
                // You can provide additional details about the boss here
            }
            break;
    }
}

void exploreUnknownArea(Player *player, Weapon *weapons, int numWeapons, Armor *armors, int numArmors, Item *items, int numItems) {
    printf("You venture into an unknown area, hoping to discover valuable items!\n");

    // Randomly determine what the player finds
    int foundType = rand() % 3; // 0: Weapon, 1: Armor, 2: Item

    switch (foundType) {
        case 0:
            if (numWeapons > 0) {
                int weaponIndex = rand() % numWeapons;
                printf("You find a weapon: %s\n", weapons[weaponIndex].name);
                // Implement logic to add the weapon to the player's inventory
            }
            break;

        case 1:
            if (numArmors > 0) {
                int armorIndex = rand() % numArmors;
                printf("You find armor: %s\n", armors[armorIndex].name);
                // Implement logic to add the armor to the player's inventory
            }
            break;

        case 2:
            if (numItems > 0) {
                int itemIndex = rand() % numItems;
                printf("You find an item: %s\n", items[itemIndex].name);
                // Implement logic to add the item to the player's inventory
            }
            break;
    }
}

void nightTimeEncounter(Player *player, Enemy *enemy, Item *magicItems, int numMagicItems) {
    printf("It's nighttime. You may find magic-related loot and face challenging enemies!\n");

    // Encounter enemy
    if (rand() % 100 < enemy->poisonChance) {
        printf("You encounter an enemy: %s\n", enemy->name);
        printf("The enemy poisons you, weakening your attributes!\n");
        player->poisonResistance -= 10;
        player->magicResistance -= 10;
    } else {
        printf("You encounter an enemy: %s\n", enemy->name);
        // Implement player-enemy combat logic here
        // player->health -= enemy->damage;
        // enemy->health -= player->damage;
    }

    // Acquire loot
    if (rand() % 100 < enemy->magicLootChance && numMagicItems > 0) {
        int magicItemIndex = rand() % numMagicItems;
        printf("You find magic-related loot: %s\n", magicItems[magicItemIndex].name);
        // Implement logic to add the magic item to the player's inventory
    }
}

void recruitKnight(Player *player, Knight *knight) {
    printf("You encounter a noble knight. They are willing to fight for you!\n");

    int recruitmentMethod = rand() % 2; // 0: Fight, 1: Buy

    switch (recruitmentMethod) {
        case 0:
            printf("You challenge %s to a fight!\n", knight->name);

            // Implement player-knight combat logic here
            // player->health -= knight->damage;
            // knight->health -= player->damage;

            if (player->health <= 0) {
                printf("You have been defeated by %s.\n", knight->name);
            } else {
                printf("Congratulations! You have defeated %s!\n", knight->name);
                // Implement logic to add the knight to the player's allies or party
                // For example: player->allies[numAllies++] = *knight;
            }
            break;

        case 1:
            if (player->gold >= knight->buyCost) {
                printf("You have recruited %s to fight for you!\n", knight->name);
                player->gold -= knight->buyCost;

                // Implement logic to add the knight to the player's allies or party
                // For example: player->allies[numAllies++] = *knight;
            } else {
                printf("You do not have enough gold to recruit %s.\n", knight->name);
            }
            break;
    }
}

void hallOfFame(Player *player, Boss *bosses, int numBosses) {
    printf("Welcome to the Hall of Fame! Defeat all bosses to claim your title!\n");

    for (int i = 0; i < numBosses; i++) {
        Boss currentBoss = bosses[i];
        printf("Boss #%d: %s\n", i + 1, currentBoss.name);

        // Implement player-boss combat logic here
        // player->health -= currentBoss.damage;

        if (player->health <= 0) {
            printf("You have been defeated by %s.\n", currentBoss.name);
            break; // Player is defeated, stop the hall of fame challenge
        } else {
            printf("Congratulations! You have defeated %s!\n", currentBoss.name);
        }
    }

    // Reward the player with an expanded inventory
    printf("Congratulations! You have completed the Hall of Fame challenge!\n");
    printf("You have been rewarded with an expanded inventory of 20 slots!\n");

    Inventory newInventory;
    newInventory.numItems = 0;

    // Transfer items from the old inventory to the new inventory
    for (int i = 0; i < player->inventory.numItems && i < 20; i++) {
        newInventory.items[i] = player->inventory.items[i];
        newInventory.numItems++;
    }

    player->inventory = newInventory;
}

void encounterEnemyWithHeavyArmor(Player *player, Enemy *enemy, Armor *armors, int numArmors, Helmet *helmets, int numHelmets, Item *defenseItems, int numDefenseItems) {
    printf("You encounter an enemy with heavy armor!\n");

    // Implement player-enemy combat logic here
    // player->health -= enemy->damage;

    if (rand() % 100 < 30) {
        int lootType = rand() % 3; // 0: No loot, 1: Armor, 2: Helmet, 3: Defense item

        if (lootType == 1 && numArmors > 0) {
            int armorIndex = rand() % numArmors;
            printf("The enemy dropped heavy armor: %s\n", armors[armorIndex].name);
            // Implement logic to add the armor to the player's inventory
        } else if (lootType == 2 && numHelmets > 0) {
            int helmetIndex = rand() % numHelmets;
            printf("The enemy dropped a helmet: %s\n", helmets[helmetIndex].name);
            // Implement logic to add the helmet to the player's inventory
        } else if (lootType == 3 && numDefenseItems > 0) {
            int defenseItemIndex = rand() % numDefenseItems;
            printf("The enemy dropped a defense item: %s\n", defenseItems[defenseItemIndex].name);
            // Implement logic to add the defense item to the player's inventory
        }
    }
}

void defeatMultiElementBoss(Player *player, Boss *boss) {
    printf("You face a formidable boss with powers from all elements!\n");

    // Implement player-boss combat logic here
    // player->health -= boss->damage;
    // boss->health -= player->damage;

    if (player->health <= 0) {
        printf("You have been defeated by the multi-element boss!\n");
    } else if (boss->health <= 0) {
        printf("Congratulations! You have defeated the multi-element boss!\n");
        printf("You are rewarded with a big gift!\n");

        // Implement logic to reward the player with a big gift
    }
}


void simulateRainfall(Player *player, Enemy *enemies, int numEnemies, Item *waterItems, int numWaterItems) {
    printf("Rain begins to fall.\n");

    int enemyEncounterChance = 50; // 50% chance to encounter an enemy
    int lootDropChance = 30; // 30% chance to drop loot from enemies

    if (rand() % 100 < enemyEncounterChance) {
        int enemyIndex = rand() % numEnemies;
        printf("You encounter an enemy: %s\n", enemies[enemyIndex].name);

        // Implement player-enemy combat logic here
        // player->health -= enemies[enemyIndex].damage;

        if (rand() % 100 < lootDropChance) {
            int lootType = rand() % 2; // 0: No loot, 1: Water item
            
            if (lootType == 1 && numWaterItems > 0) {
                int itemIndex = rand() % numWaterItems;
                printf("The enemy dropped a water-related item: %s\n", waterItems[itemIndex].name);
                // Implement logic to add the item to the player's inventory
            }
        }
    } else {
        printf("You enjoy a peaceful moment in the rain.\n");
    }
}

void enterProhibitedArea(Player *player, Enemy *enemy) {
    printf("You enter a prohibited area.\n");

    // Simulate a powerful enemy in the prohibited area
    printf("You encounter a powerful enemy: %s\n", enemy->name);

    // Implement player-enemy combat logic here
    // player->health -= enemy->damage;
    // enemy->health -= player->damage;

    if (player->health <= 0) {
        printf("You have been defeated!\n");
        player->gold = 0; // Lose all loot
    } else {
        printf("You have defeated the enemy!\n");
    }
}

void increaseDamageRandomPercent(Player *player) {
    printf("You feel a surge of power!\n");

    int minPercent = 10; // Minimum damage increase percentage
    int maxPercent = 25; // Maximum damage increase percentage

    // Generate a random percentage increase within the range
    int percentIncrease = rand() % (maxPercent - minPercent + 1) + minPercent;

    // Calculate the new damage value with the percentage increase
    player->damage += (player->damage * percentIncrease) / 100;

    printf("Your damage has been increased by %d%%.\n", percentIncrease);
}

void enterRainbowBridgeToHeaven(Player *player, Item *heavenItems, int numHeavenItems, Weapon *heavenWeapons, int numHeavenWeapons) {
    printf("You step onto the Rainbow Bridge to Heaven!\n");

    int heavenLootChance = 50; // 50% chance to gain heaven-themed loot
    int purchaseChoice;

    if (rand() % 100 < heavenLootChance) {
        int lootType = rand() % 2; // 0: Item, 1: Weapon
        
        if (lootType == 0 && numHeavenItems > 0) {
            int itemIndex = rand() % numHeavenItems;
            printf("You find a heaven-themed item: %s\n", heavenItems[itemIndex].name);
            // Implement logic to add the item to the player's inventory
        } else if (numHeavenWeapons > 0) {
            int weaponIndex = rand() % numHeavenWeapons;
            printf("You find a heaven-themed weapon: %s\n", heavenWeapons[weaponIndex].name);
            // Implement logic to add the weapon to the player's inventory
        }
    } else {
        printf("The heavens smile upon you, but you find no special loot.\n");
    }

    printf("Do you wish to purchase an item or weapon? (0: No, 1: Item, 2: Weapon): ");
    scanf("%d", &purchaseChoice);

    switch (purchaseChoice) {
        case 1:
            if (numHeavenItems > 0) {
                int itemIndex = rand() % numHeavenItems;
                if (player->gold >= heavenItems[itemIndex].value) {
                    printf("You purchase the heaven-themed item: %s\n", heavenItems[itemIndex].name);
                    player->gold -= heavenItems[itemIndex].value;
                    // Implement logic to add the item to the player's inventory
                } else {
                    printf("You don't have enough gold to purchase this item.\n");
                }
            } else {
                printf("No heaven-themed items available for purchase.\n");
            }
            break;

        case 2:
            if (numHeavenWeapons > 0) {
                int weaponIndex = rand() % numHeavenWeapons;
                if (player->gold >= heavenWeapons[weaponIndex].value) {
                    printf("You purchase the heaven-themed weapon: %s\n", heavenWeapons[weaponIndex].name);
                    player->gold -= heavenWeapons[weaponIndex].value;
                    // Implement logic to add the weapon to the player's inventory
                } else {
                    printf("You don't have enough gold to purchase this weapon.\n");
                }
            } else {
                printf("No heaven-themed weapons available for purchase.\n");
            }
            break;

        default:
            printf("You decide not to make a purchase.\n");
            break;
    }
}

void encounterHugeAmountOfEnemies(Player *player, Enemy *enemies, int numEnemies, Item *items, int numItems, Weapon *weapons, int numWeapons) {
    printf("You encounter a huge amount of enemies!\n");

    int lootDropChance = 30; // 30% chance to drop loot from each enemy

    for (int i = 0; i < numEnemies; i++) {
        printf("Defeating enemy %s...\n", enemies[i].name);
        
        // Implement logic for player-enemy combat
        // playerHealth -= enemies[i].damage;
        
        if (rand() % 100 < lootDropChance) {
            int itemType = rand() % 2; // 0: Item, 1: Weapon
            
            if (itemType == 0 && numItems > 0) {
                int itemIndex = rand() % numItems;
                printf("Enemy dropped an item: %s\n", items[itemIndex].name);
                // Implement logic to add the item to the player's inventory
            } else if (numWeapons > 0) {
                int weaponIndex = rand() % numWeapons;
                printf("Enemy dropped a weapon: %s\n", weapons[weaponIndex].name);
                // Implement logic to add the weapon to the player's inventory
            }
        }
    }
}

void crossSwitchMatrices(int matrix1[3], int matrix2[5]) {
    int temp[5];

    // Copy values from matrix2 to temp
    for (int i = 0; i < 5; i++) {
        temp[i] = matrix2[i];
    }

    // Copy values from matrix1 to matrix2
    for (int i = 0; i < 5; i++) {
        matrix2[i] = matrix1[i];
    }

    // Copy values from temp to matrix1
    for (int i = 0; i < 3; i++) {
        matrix1[i] = temp[i];
    }
}

void enterLightningStrikeArea(Player *player, Item *lightningItems, int numLightningItems, Weapon *lightningWeapons, int numLightningWeapons) {
    printf("You enter an area prone to lightning strikes.\n");

    int healthDecrease = 25; // Health decrease due to lightning strike

    player->health -= healthDecrease;

    if (player->health < 0) {
        player->health = 0;
    }

    printf("A lightning strike hits you, and your health decreases by %d.\n", healthDecrease);

    // Random chance to find a lightning-related item or weapon
    int foundItemChance = rand() % 2; // 50% chance to find an item

    if (foundItemChance == 0 && numLightningItems > 0) {
        int itemIndex = rand() % numLightningItems;
        Item item = lightningItems[itemIndex];
        printf("You find a lightning-related item: %s\n", item.name);
        // Implement logic to add the item to the player's inventory
    } else if (numLightningWeapons > 0) {
        int weaponIndex = rand() % numLightningWeapons;
        Weapon weapon = lightningWeapons[weaponIndex];
        printf("You find a lightning-related weapon: %s\n", weapon.name);
        // Implement logic to add the weapon to the player's inventory
    } else {
        printf("You search the area, but find nothing lightning-related.\n");
    }
}

void enterForest(Player *player) {
    printf("You enter the mysterious forest.\n");

    float encounterChanceIncrease = 1.5; // 50% increase in encounter chance
    float damageReduction = 0.9; // 10% damage reduction

    player->encounterChance *= encounterChanceIncrease;
    player->damage *= damageReduction;

    printf("The atmosphere of the forest increases your chance of encountering enemies and decreases your damage.\n");
}


void powerOfHeaven(Player *player) {
    printf("The power of heaven blesses you!\n");

    int healthIncrease = 50;
    int damageIncrease = 20;

    player->maxHealth += healthIncrease;
    player->damage += damageIncrease;

    printf("Your max health has increased by %d. Your damage has increased by %d.\n", healthIncrease, damageIncrease);
}

void applyTemperatureEffects(Player *player, Enemy *enemies, Boss *boss, int temperature) {
    if (temperature > 30) {
        printf("It's extremely hot!\n");

        // Apply temperature-related effects to the player and enemies
        player->health -= 10; // Player loses health due to extreme heat
        
        enemies->damage -= 5; // Enemies' damage is reduced due to sluggishness from heat
        
        if (boss != NULL) {
            boss->damage -= 10; // Boss's damage is significantly reduced due to heat fatigue
        }
    } else if (temperature < 10) {
        printf("It's freezing cold!\n");

        // Apply temperature-related effects to the player and enemies
        player->health -= 5; // Player loses health due to extreme cold

        enemies->health -= 10; // Enemies lose health due to the cold

        if (boss != NULL) {
            boss->health -= 20; // Boss loses health due to the cold
        }
    } else {
        printf("The temperature is moderate.\n");
        // No significant effects on player and enemies
    }
}

void playerEnterCampus(Player *player, Shop *shop, Item *enchantedItems, int numEnchantedItems, Weapon *enchantedWeapons, int numEnchantedWeapons) {
    printf("Player enters the magical campus.\n");

    int choice;
    printf("Welcome to the magical campus shop!\n");
    printf("1. Purchase enchanted item\n");
    printf("2. Purchase enchanted weapon\n");
    printf("3. Leave the shop\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (numEnchantedItems > 0) {
                int itemIndex = rand() % numEnchantedItems;
                Item item = enchantedItems[itemIndex];

                if (player->gold >= item.value) {
                    printf("You purchased an enchanted item: %s\n", item.name);
                    player->gold -= item.value;
                    // Implement logic to add the item to the player's inventory
                } else {
                    printf("You don't have enough gold to purchase this item.\n");
                }
            } else {
                printf("No enchanted items available for purchase.\n");
            }
            break;

        case 2:
            if (numEnchantedWeapons > 0) {
                int weaponIndex = rand() % numEnchantedWeapons;
                Weapon weapon = enchantedWeapons[weaponIndex];

                if (player->gold >= weapon.value) {
                    printf("You purchased an enchanted weapon: %s\n", weapon.name);
                    player->gold -= weapon.value;
                    // Implement logic to equip the weapon to the player
                } else {
                    printf("You don't have enough gold to purchase this weapon.\n");
                }
            } else {
                printf("No enchanted weapons available for purchase.\n");
            }
            break;

        case 3:
            printf("Leaving the shop.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}


void playerRest(Player *player) {
    printf("Player decides to rest.\n");

    int healthGain = rand() % 41 + 10; // Generate a random number between 10 and 50

    printf("Resting...\n");
    player->health += healthGain;

    if (player->health > player->maxHealth) {
        player->health = player->maxHealth;
    }

    printf("%s's health has been restored by %d points. Current health: %d\n", player->name, healthGain, player->health);
}


void playerOpenGift(Player *player, Boss *boss, int explorationCompleted) {
    printf("Player has a chance to open a gift!\n");

    int giftChoice = rand() % 2; 

    if (giftChoice == 0) {
        printf("The gift contains a valuable item!\n");
        // Implement logic for adding the valuable item to the player's inventory
    } else {
        printf("The gift is guarded by a powerful boss!\n");
        
        if (boss != NULL) {
            printf("Player encounters Boss: %s\n", boss->name);
            attackPlayer(boss, player);
            
            if (player->health > 0) {
                printf("Congratulations! You defeated the boss and earned the gift.\n");
                // Implement logic for adding rewards to the player's inventory
            } else {
                printf("You were defeated by the boss. Better luck next time!\n");
            }
        } else {
            if (explorationCompleted) {
                printf("You have completed the required exploration. The gift is yours!\n");
                // Implement logic for adding rewards to the player's inventory
            } else {
                printf("You haven't completed the required exploration yet. Come back later!\n");
            }
        }
    }
}


void playerEncounterEnemy(Player *player, Enemy *enemy) {
    printf("Player encounters: %s\n", enemy->name);
    attackPlayer(enemy,player);
}

void playerEncounterBoss(Player *player, Boss *boss) {
    printf("Player encounters Boss: %s\n", boss->name);
    attackPlayer(boss,player);
}

void playerPickUpWeapon(Player *player, Weapon *weapon) {
    printf("Player picks up weapon: %s\n", weapon->name);
    player->weapon = createWeapon(weapon->name,weapon->damage,weapon->value);
}

void playerEncounterNpc(Player *player, Npc *npc, Boss *boss, Item *items, Weapon *weapons, Shop *shop, int numItems, int numWeapons) {
    printf("Player encounters NPC: %s\n", npc->name);

    int interactionChoice = rand() % 3; 
    switch (interactionChoice) {
        case 0:
            printf("The NPC offers a chance to fight the boss!\n");
            attackPlayer(boss, player);
            break;
        case 1:
            if (numItems > 0) {
                int itemIndex = rand() % numItems;
                printf("The NPC offers to sell an item: %s\n", items[itemIndex].name);
                spendGold(player,shop,npc);
            } else {
                printf("The NPC has no items to sell.\n");
            }
            break;
        case 2:
            int giveawayChoice = rand() % 2; 

            if (giveawayChoice == 0 && numWeapons > 0) {
                int weaponIndex = rand() % numWeapons;
                printf("The NPC gives you a weapon: %s\n", weapons[weaponIndex].name);
                player->weapon = weapons[weaponIndex];
            } else if (numItems > 0) {
                int itemIndex = rand() % numItems;
                printf("The NPC gives you an item: %s\n", items[itemIndex].name);
                // Implement logic for giving the item to the player
            } else {
                printf("The NPC has nothing to give.\n");
            }
            break;
    }
}

void playerEnterShop(Player *player, Shop *shop) {
    printf("Player enters shop.\n");

    int timeOfDay = rand() % 3; 
    int goldSpent = rand() % 20 + 1;

    switch (timeOfDay) {
        case 0:
            printf("It's morning at the shop!\n");
            // Offer morning-specific items and weapons
            break;

        case 1:
            printf("It's afternoon at the shop!\n");
            // Offer afternoon-specific items and weapons
            break;

        case 2:
            printf("It's evening at the shop!\n");
            // Offer evening-specific items and weapons
            break;
    }

    printf("Player spends %d gold.\n", goldSpent);
    player->gold -= goldSpent;
}

void playerEnterHome(Player *player, Home *home,int itemIndex) {
    printf("Player enters home.\n");

    player->health += 50;
    printf("%s gains 50 health. Health: %d\n", player->name, player->health);

    printf("Opening the storage...\n");
    displayStorageContents(&(home->storage));

    printf("Enter the index of the item to switch (or -1 to cancel): ");

    if (itemIndex >= 0 && itemIndex < home->storage.numItems) {
        // Perform the item switch logic
        // implement logic for switching items and weapons here
        printf("You switched items.\n");
    } else if (itemIndex == -1) {
        printf("Item switching cancelled.\n");
    } else {
        printf("Invalid item index.\n");
    }
}

void playerEnterWildy(Player *player, Enemy *enemies, int numEnemies, Npc *npcs, int numNpcs, Item *items, int numItems, Weapon *weapons, int numWeapons) {
    printf("Player enters the wilderness.\n");

    int encounterChoice = rand() % 3; 

    switch (encounterChoice) {
        case 0:
            if (numEnemies > 0) {
                int enemyIndex = rand() % numEnemies;
                printf("Player encounters an enemy: %s\n", enemies[enemyIndex].name);
                attackPlayer(&(enemies[enemyIndex]), player);
            } else {
                printf("No enemies in the wilderness.\n");
            }
            break;
        case 1:
            if (numNpcs > 0) {
                int npcIndex = rand() % numNpcs;
                printf("Player encounters an NPC: %s\n", npcs[npcIndex].name);
                // Implement logic for interacting with the NPC
            } else {
                printf("No NPCs in the wilderness.\n");
            }
            break;
        case 2:
            int foundChoice = rand() % 2; 

            if (foundChoice == 0 && numItems > 0) {
                int itemIndex = rand() % numItems;
                playerPickupItem(player, items, numItems, weapons, numWeapons);
                printf("Player finds an item: %s\n", items[itemIndex].name);
                // Implement logic for adding the found item to the player's inventory
            } else if (numWeapons > 0) {
                int weaponIndex = rand() % numWeapons;
                playerPickupItem(player, items, numItems, weapons, numWeapons);
                printf("Player finds a weapon: %s\n", weapons[weaponIndex].name);
                // Implement logic for adding the found weapon to the player's inventory
            } else {
                printf("No items or weapons found.\n");
            }
            break;
    }
}

void playerPickupItem(Player *player, Item *items, int numItems, Weapon *weapons, int numWeapons) {
    printf("Player picks up an item from the map.\n");

    int pickupChoice = rand() % 2; 
    if (pickupChoice == 0 && numItems > 0) {
        int itemIndex = rand() % numItems;
        printf("Player picks up an item: %s\n", items[itemIndex].name);
        // Implement logic for adding the picked up item to the player's inventory
    } else if (numWeapons > 0) {
        int weaponIndex = rand() % numWeapons;
        printf("Player picks up a weapon: %s\n", weapons[weaponIndex].name);
        // Implement logic for adding the picked up weapon to the player's inventory
    } else {
        printf("No items or weapons to pick up.\n");
    }
}

