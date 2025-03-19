#pragma once

#define TOTAL_WEAPONS  3

typedef struct weapon {
	char* name;
	double damage;
}WEAPON;

typedef struct armour {
	char* name;
	double protection;
}ARMOUR;

WEAPON* createWeapon(char* name, double damage);
void destroyWeapon(WEAPON* weapon);

WEAPON* generateRandomWeapon();

ARMOUR* createArmour(char* name, double protection);
void destroyArmour(ARMOUR* armour);

ARMOUR* generateRandomArmour();
void generateLoot(WEAPON* weapon, ARMOUR* armour);