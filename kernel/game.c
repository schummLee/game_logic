#include <stdbool.h>
#include "../logic/game_logic.c"


void game_engine(const char *name) {       
  struct GameData* _gameData;
  bool isGameRunning = true;

  

    if (isGameRunning){
        playGame(_gameData);
    }
}