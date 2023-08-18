#include <stdbool.h>
#include "../logic/game_logic.c"
#include "../socket/socketServer.c"
#include "../components/string_function.h"

MatrixFunctionMapping functionMappings[] = {
    {_coldArea, enterColdArea},
    {_desert, enterDesert},
    {_combatWithStranger, combatWithStranger},
    {_acquireImmunityAndDefuff, acquireImmunityAndDefuff},
    {_lightningStrikeAndRain, lightningStrikeAndRain},
    {_getRandomInfo, getRandomInfo},
    {_exploreUnknownArea, exploreUnknownArea},
    {_nightTimeEncounter, nightTimeEncounter},
    {_recruitKnight, recruitKnight},
    {_hallOfFame, hallOfFame},
    {_encounterEnemyWithHeavyArmor, encounterEnemyWithHeavyArmor},
    {_defeatMultiElementBoss, defeatMultiElementBoss},
    {_simulateRainfall, simulateRainfall},
    {_enterProhibitedArea, enterProhibitedArea},
    {_increaseDamageRandomPercent, increaseDamageRandomPercent},
    {_enterRainbowBridgeToHeaven, enterRainbowBridgeToHeaven},
    {_encounterHugeAmountOfEnemies, encounterHugeAmountOfEnemies},
    {_crossSwitchMatrices, crossSwitchMatrices},
    {_enterLightningStrikeArea, enterLightningStrikeArea},
    {_enterForest, enterForest},
    {_powerOfHeaven, powerOfHeaven},
    {_applyTemperatureEffects, applyTemperatureEffects},
    {_playerEnterCampus, playerEnterCampus},
    {_playerRest, playerRest},
    {_playerOpenGift, playerOpenGift},
    {_playerEncounterEnemy, playerEncounterEnemy},
    {_playerEncounterBoss, playerEncounterBoss},
    {_playerEnterWildy, playerEnterWildy},
    {_playerPickupItem, playerPickupItem},
    {_playerEncounterNpc, playerEncounterNpc},
}

void playGame(GameData *game) {
    printf("Starting the game!\n");

    applyTemperatureEffects(game->player,game->enemy, ame->boss,game->temperature);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (i == 1 && j == 1) {
                continue;
            }

            char *matrixValue = game->matrix[i][j];

            for (int k = 0; k < NUM_MAPPINGS; k++) {
                if (strcmp(matrixValue, functionMappings[k].value) == 0) {
                    functionMappings[k].function();
                    break; 
                }
            }
        }
    }

    if (game->player.health == 0) {
        printf("\nGame over!\n");
    }
}

void game_engine() {       
  bool isGameRunning = true;

  

    if (isGameRunning){
        startSocketServer();
    }
}