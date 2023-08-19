#include <stdbool.h>
#include "../logic/game_logic.c"
#include "../socket/socketServer.c"
#include "../components/string_function.h"
#include "../components/game.h"

DynamicFunctionMapping dynamicfunctionMappings[] = {
    {_coldArea, (void (*)(void *))enterColdArea, &FunctionColdAreaParams},
    {_desert, (void (*)(void *))enterDesert, &FunctionDesertParams},
    {_combatWithStranger, (void (*)(void *))combatWithStranger, &FunctionCombatWithStrangerParams},
    {_acquireImmunityAndDefuff, (void (*)(void *))acquireImmunityAndDebuff, &FunctionAcquireImmunityAndDefuffParams},
    {_lightningStrikeAndRain, (void (*)(void *))lightningStrikeAndRain, &FunctionLightningStrikeAndRainParams},
    {_getRandomInfo, (void (*)(void *))getRandomInfo, &FunctionGetRandomInfoParams},
    {_exploreUnknownArea, (void (*)(void *))exploreUnknownArea, &FunctionExploreUnknownAreaParams},
    {_nightTimeEncounter, (void (*)(void *))nightTimeEncounter, &FunctionNightTimeEncounterParams},
    {_recruitKnight, (void (*)(void *))recruitKnight, &FunctionRecruitKnightParams},
    {_hallOfFame, (void (*)(void *))hallOfFame, &FunctionHallOfFameParams},
    {_encounterEnemyWithHeavyArmor, (void (*)(void *))encounterEnemyWithHeavyArmor, &FunctionEncounterEnemyWithHeavyArmorParams},
    {_defeatMultiElementBoss, (void (*)(void *))defeatMultiElementBoss, &FunctionDefeatMultiElementBossParams},
    {_simulateRainfall, (void (*)(void *))simulateRainfall, &FunctionSimulateRainfallParams},
    {_enterProhibitedArea, (void (*)(void *))enterProhibitedArea, &FunctionEnterProhibitedAreaParams},
    {_increaseDamageRandomPercent, (void (*)(void *))increaseDamageRandomPercent, &FunctionIncreaseDamageRandomPercentParams},
    {_enterRainbowBridgeToHeaven, (void (*)(void *))enterRainbowBridgeToHeaven, &FunctionEnterRainbowBridgeToHeavenParams},
    {_encounterHugeAmountOfEnemies, (void (*)(void *))encounterHugeAmountOfEnemies, &FunctionEncounterHugeAmountOfEnemiesParams},
    {_crossSwitchMatrices, (void (*)(void *))crossSwitchMatrices, &FunctionCrossSwitchMatricesParams},
    {_enterLightningStrikeArea, (void (*)(void *))enterLightningStrikeArea, &FunctionEnterLightningStrikeAreaParams},
    {_enterForest, (void (*)(void *))enterForest, &FunctionEnterForestParams},
    {_powerOfHeaven, (void (*)(void *))powerOfHeaven, &FunctionPowerOfHeavenParams},
    {_applyTemperatureEffects, (void (*)(void *))applyTemperatureEffects, &FunctionApplyTemperatureEffectsParams},
    {_playerEnterCampus, (void (*)(void *))playerEnterCampus, &FunctionPlayerEnterCampusParams},
    {_playerRest, (void (*)(void *))playerRest, &FunctionPlayerRestParams},
    {_playerOpenGift, (void (*)(void *))playerOpenGift, &FunctionPlayerOpenGiftParams},
    {_playerEncounterEnemy, (void (*)(void *))playerEncounterEnemy, &FunctionPlayerEncounterEnemyParams},
    {_playerEncounterBoss, (void (*)(void *))playerEncounterBoss, &FunctionPlayerEncounterBossParams},
    {_playerEnterWildy, (void (*)(void *))playerEnterWildy, &FunctionPlayerEnterWildyParams},
    {_playerPickupItem, (void (*)(void *))playerPickupItem, &FunctionPlayerPickupItemParams},
    {_playerEncounterNpc, (void (*)(void *))playerEncounterNpc, &FunctionPlayerEncounterNpcParams}
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
        dynamicFunctionMappings[k].function(dynamicFunctionMappings[k].params);
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