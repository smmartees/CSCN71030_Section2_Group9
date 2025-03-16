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