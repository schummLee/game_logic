#ifndef WEAPON_H
#define WEAPON_H


typedef struct {
    char name[50];
    int damage;
} Weapon;

Weapon createWeapon(const char *name, int damage);

const char* getWeaponName(const Weapon *weapon);

int getWeaponDamage(const Weapon *weapon);

#endif
