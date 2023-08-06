#include <stdbool.h>
#include "boss.h"
#include "enemy.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "weapon.h"
#include "npc.h"
#include "map.h"
#include "matrix_generator.h"

void game_engine(const char *name) {       
  struct GameData* _gameData;
  bool isGameRunning = true;

  

    if (isGameRunning){
        playGame(_gameData);
    }
}