#pragma once
#include <stdio.h>

#define TOTAL_WEAPONS  3
#define WORD_LIMIT  100


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

WEAPON* generateRandomWeapon(double diffMod);

ARMOUR* createArmour(char* name, double protection);
void destroyArmour(ARMOUR* armour);

ARMOUR* generateRandomArmour(double diffMod);
//void generateLoot(WEAPON* weapon, ARMOUR* armour);

void saveWeapon(FILE* fp, WEAPON* weapon);


WEAPON* loadWeapon(FILE* fp);

void saveArmour(FILE* fp, ARMOUR* armour);
ARMOUR* loadArmour(FILE* fp);