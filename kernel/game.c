#include <stdbool.h>
#include "../logic/game_logic.c"

void playGame(GameData *game) {
    printf("Starting the game!\n");

    for (int mapIndex = 0; mapIndex < NUM_MAPS; mapIndex++) {
        printf("\nEntering Map %d:\n", mapIndex + 1);
        printMatrix(game->map);

        if (rand() % 2 == 0) {
            int enemyIndex = rand() % NUM_ENEMIES;
            playerEncounterEnemy(&(game->player), &(game->enemy));
        }

        if (rand() % 4 == 0) {
            int bossIndex = rand() % NUM_BOSSES;
            playerEncounterBoss(&(game->player), &(game->boss));
        }

        if (rand() % 3 == 0) {
            int weaponIndex = rand() % NUM_WEAPONS;
            playerPickUpWeapon(&(game->player), &(game->weapon));
        }
    }

    if (game->player.health == 0) {
        printf("\nGame over!\n");
    }
}

void game_engine(const char *name) {       
  struct GameData* _gameData;
  bool isGameRunning = true;

  

    if (isGameRunning){
        playGame(_gameData);
    }
}