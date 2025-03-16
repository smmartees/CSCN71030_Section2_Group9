#pragma once

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

WEAPON* createRandomWeapons();

ARMOUR* createArmour(char* name, double protection);
void destroyArmour(ARMOUR* armour);