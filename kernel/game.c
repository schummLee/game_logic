#include <stdbool.h>
#include "../logic/game_logic.c"
#include "../socket/socketServer.c"
#include "../components/string_function.h"
#include "../components/game.h"

MatrixFunctionMapping functionMappings[] = {
    {_coldArea, (FunctionEnterColdArea)enterColdArea},
    {_desert, (FunctionEnterDesert)enterDesert},
    {_combatWithStranger, (FunctionCombatWithStranger)combatWithStranger},
    {_acquireImmunityAndDefuff, (FunctionWithPlayerParam)acquireImmunityAndDebuff},
    {_lightningStrikeAndRain, (FunctionLightningStrikeAndRain)lightningStrikeAndRain},
    {_getRandomInfo, (FunctionGetRandomItem)getRandomInfo},
    {_exploreUnknownArea, (FunctionExploreUnknownArea)exploreUnknownArea},
    {_nightTimeEncounter, (FunctionNightTimeEncounter)nightTimeEncounter},
    {_recruitKnight, (FunctionRecruitKnight)recruitKnight},
    {_hallOfFame, (FunctionHallOfFame)hallOfFame},
    {_encounterEnemyWithHeavyArmor, (FunctionencounterEnemyWithHeavyArmor)encounterEnemyWithHeavyArmor},
    {_defeatMultiElementBoss, (FunctionDefeatMultiElementBoss)defeatMultiElementBoss},
    {_simulateRainfall, (FunctionSimulateRainfall)simulateRainfall},
    {_enterProhibitedArea, (FunctionEnterProhibitedArea)enterProhibitedArea},
    {_increaseDamageRandomPercent, (FunctionWithPlayerParam)increaseDamageRandomPercent},
    {_enterRainbowBridgeToHeaven, (FunctionEnterRainbowBridgeToHeaven)enterRainbowBridgeToHeaven},
    {_encounterHugeAmountOfEnemies, (FunctionEncounterHugeAmountOfEnemies)encounterHugeAmountOfEnemies},
    {_crossSwitchMatrices, (FunctionCrossSwitchMatrices)crossSwitchMatrices},
    {_enterLightningStrikeArea, (FunctionEnterLightningStrikeArea)enterLightningStrikeArea},
    {_enterForest, (FunctionWithPlayerParam)enterForest},
    {_powerOfHeaven, (FunctionWithPlayerParam)powerOfHeaven},
    {_applyTemperatureEffects, (FunctionApplyTemperatureEffects)applyTemperatureEffects},
    {_playerEnterCampus, (FunctionPlayerEnterCampus)playerEnterCampus},
    {_playerRest, (FunctionWithPlayerParam)playerRest},
    {_playerOpenGift, (FunctionPlayerOpenGift)playerOpenGift},
    {_playerEncounterEnemy, (FunctionPlayerEncounterEnemy)playerEncounterEnemy},
    {_playerEncounterBoss, (FunctionPlayerEncounterBoss)playerEncounterBoss},
    {_playerEnterWildy, (FunctionPlayerEnterWildy)playerEnterWildy},
    {_playerPickupItem, (FunctionPlayerPickupItem)playerPickupItem},
    {_playerEncounterNpc, (FunctionPlayerEncounterNpc)playerEncounterNpc},
};

void playGame(GameData *game) {
    printf("Starting the game!\n");

    applyTemperatureEffects(game->player,game->enemy, game->boss,game->temperature);

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