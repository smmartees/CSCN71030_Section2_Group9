#include "loot.h"

#include <stdio.h>
#include <stdlib.h>

//Function to create weapon 
WEAPON* createWeapon(char* name, double damage) {
	WEAPON* newWeapon = (WEAPON*)malloc(sizeof(WEAPON));

	if (newWeapon == NULL) {
		fprintf(stderr, "Memory Allocation for weapon has failed\n");
		exit(EXIT_FAILURE);
	}
	newWeapon->name = name;
	newWeapon->damage = damage;
	return newWeapon;

}
//function to destroy a weapon
void destroyWeapon(WEAPON* weapon) {
	free(weapon);
}
//Function To create 3 predefined weapons and selects one weapon using random generator
WEAPON* generateRandomWeapon() {


	int randomSelector;
	WEAPON* gameWeapons[3];

	gameWeapons[0] = createWeapon("Lightsaber sword", 25.0);
	gameWeapons[1]= createWeapon("Lightsaber axe", 30.0);
	gameWeapons[2] = createWeapon("Lightsaber double sword", 35.0);

	randomSelector = rand() % 3;
	WEAPON* selectedWeapon = gameWeapons[randomSelector];

	for (int i = 0; i < TOTAL_WEAPONS; i++) {
		if (i != randomSelector) {
			destroyWeapon(gameWeapons[i]);
		}
	}
	return selectedWeapon;

}
//Function to create armour
ARMOUR* createArmour(char* name, double protection) {
	ARMOUR* newArmour = (ARMOUR*)malloc(sizeof(ARMOUR));

	if (newArmour == NULL) {
		fprintf(stderr, "Memory Allocation for armour has failed\n");
		exit(EXIT_FAILURE);
	}
	newArmour->name = name;
	newArmour->protection = protection;
	return newArmour;

}
//Function to destroy armour
void destroyArmour(ARMOUR* armour) {
	free(armour);
}

ARMOUR* generateRandomArmour() {
	
	int randomSelector;
	ARMOUR* gameArmours[3];

	gameArmours[0] = createArmour("Mandalorian armor", 20.0);
	gameArmours[1] = createArmour("Clone Trooper armor", 25.0);
	gameArmours[2] = createArmour("Imperial Stormtrooper armor", 30.0);

	randomSelector = rand() % 3;
	ARMOUR* selectedArmour = gameArmours[randomSelector];

	for (int i = 0; i < TOTAL_WEAPONS; i++) {
		if (i != randomSelector) {
			destroyArmour(gameArmours[i]);
		}
	}
	return selectedArmour;
}