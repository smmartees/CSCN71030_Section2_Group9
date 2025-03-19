#include "loot.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	srand(time(NULL));

	// Weapon Build and weapon types
	char* weapons[3][2] = {
		  {"Fire", "Sword"},
		  {"Light", "Gun"},
		  {"Thunder", "Spear"}
	};
	int randomRow = rand() % 3;
	// Allocate memory for the weapon name
	int nameLength = strlen(weapons[randomRow][0]) + strlen(weapons[randomRow][1]) ;
	char* weaponName = (char*)malloc(nameLength * sizeof(char));
	if (!weaponName) {
		fprintf(stderr, "Memory allocation failed for weapon name\n");
		exit(EXIT_FAILURE);
	}

	//string concatenation
	strcpy(weaponName, weapons[randomRow][0]);
	strcat(weaponName, " ");
	strcat(weaponName, weapons[randomRow][1]);

	// damage between 15 and 25
	int damage = (rand() % 11) + 15; 

	return createWeapon(weaponName, damage);
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
	
	srand(time(NULL));
	int randomSelector;
	char* armours[3][2] = {
		  {"Fire", "helmet"},
		  {"Light", "chestpiece"},
		  {"Thunder", "boot"}
	};

	int randomRow = rand() % 3;

	
	int nameLength = strlen(armours[randomRow][0]) + strlen(armours[randomRow][1]);
	char* armourName = (char*)malloc(nameLength * sizeof(char));
	if (!armourName) {
		fprintf(stderr, "Memory allocation failed for weapon name\n");
		exit(EXIT_FAILURE);
	}

	//string concatenation
	strcpy(armourName, armours[randomRow][0]);
	strcat(armourName, " ");
	strcat(armourName, armours[randomRow][1]);

	// damage between 15 and 25
	int damage = (rand() % 11) + 15;


	return createArmour(armourName, damage);
}
void generateLoot(WEAPON* weapon, ARMOUR* armour) {
	srand(time(NULL));

	if (rand() % 2 == 0) {
		*weapon = *generateRandomWeapon();
		printf("You found a weapon: %s with %.2f damage\n", weapon->name, weapon->damage);
	}
	else {
		*armour = *generateRandomArmour();
		printf("You found an armour: %s with %.2f protection\n", armour->name, armour->protection);
	}
}