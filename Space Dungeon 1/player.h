#pragma once
#include "loot.h" /// should work once the loot module is added to the program

#define HEALTH_DEFAULT 100.0
#define POTION_DEFAULT 0

typedef struct player {
	double health;
	ARMOUR armour;
	WEAPON weapon;
	int potions;

}PLAYER, * PPLAYER;

// creation in heap
PPLAYER createPlayer(double health, ARMOUR armour, WEAPON weapon, int potions);

// setters
void changeHealth(PPLAYER player, double damage);
void changeArmour(PPLAYER player, ARMOUR armour);
void changeWeapon(PPLAYER player, WEAPON weapon);
void addPotion(PPLAYER player);
void usePotion(PPLAYER player);

// getters
char* getWeaponName(PPLAYER player);
char* getArmourName(PPLAYER player);
double getArmourProtection(PPLAYER player);
int getPotionCount(PPLAYER player);
double attack(PPLAYER player);

// display
void displayPlayer(PPLAYER player);

// free memory
void destroyPlayer(PPLAYER player);