#include "weapon.h"
#include <string.h>

Weapon createWeapon(const char *name, int damage, int value) {
    Weapon newWeapon;
    strcpy(newWeapon.name, name);
    newWeapon.damage = damage;
    newWeapon.value = value;
    return newWeapon;
}

const char* getWeaponName(const Weapon *weapon) {
    return weapon->name;
}

int getWeaponDamage(const Weapon *weapon) {
    return weapon->damage;
}

int getWeaponValue(const Weapon *weapon) {
    return weapon->value;
}