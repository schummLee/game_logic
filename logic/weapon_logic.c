#include "weapon.h"
#include <string.h>

Weapon createWeapon(const char *name, int damage) {
    Weapon newWeapon;
    strcpy(newWeapon.name, name);
    newWeapon.damage = damage;
    return newWeapon;
}

const char* getWeaponName(const Weapon *weapon) {
    return weapon->name;
}

int getWeaponDamage(const Weapon *weapon) {
    return weapon->damage;
}
