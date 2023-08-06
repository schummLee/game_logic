#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matrix_generator.h" 

const char *categories[] = {
    "enemy", "map", "boss", "weapon", "logic", "player"
};

const char *enemyValues[] = {
    "Goblin", "Skeleton", "Orc"
};

const char *mapValues[] = {
    "Forest", "Desert", "Castle"
};

const char *bossValues[] = {
     "Dragon", "Witch", "Demon"
};

const char *weaponValues[] = {
    "Sword", "Bow", "Hammer"
};

const char *logicValues[] = {
     "Puzzle", "Platformer", "RPG"
};

const char *playerValues[] = {
    "Knight", "Mage", "Rogue"
};

void generateAndPrintRandomMatrices(int numMatrices) {

    srand(time(NULL));

    for (int i = 0; i < numMatrices; i++) {
        char matrix[MATRIX_SIZE][MATRIX_SIZE][MAX_STRING_LENGTH];

        printf("Matrix %d:\n", i + 1);

        generateRandomMatrix(matrix);
        printMatrix(matrix);

        printf("\n");
    }
}

// int main() {
//     // Call the function to generate and print random matrices
//     generateAndPrintRandomMatrices(6);

//     return 0;
// }