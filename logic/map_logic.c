#include "../components/map.h"
#include "../components/player.h"

Map createMap(const char *type, int debuff, int buff) {
    Map map;
    strncpy(map.type, type, MAX_STRING_LENGTH - 1);
    map.type[MAX_STRING_LENGTH - 1] = '\0';
    map.debuff = debuff;
    map.buff = buff;
    return map;
}

void applyMapEffects(Player *player, const Map *map) {
    printf("Player enters %s map.\n", map->type);

    if (map->debuff < 0) {
        printf("Debuff applied: Health -%d\n", -map->debuff);
        player->health -= -map->debuff;
    } else if (map->buff > 0) {
        printf("Buff applied: Health +%d\n", map->buff);
        player->health += map->buff;
    }
}
