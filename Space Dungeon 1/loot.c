#define _CRT_SECURE_NO_WARNINGS
#include "loot.h"
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


//Function to create weapon 
WEAPON* createWeapon(char* name, double damage) {

	//for boundary testing 
	if (name == NULL || strlen(name) == 0 || damage < 0) {
		return NULL;  // Ensure invalid input returns NULL
	}

	WEAPON* newWeapon = (WEAPON*)malloc(sizeof(WEAPON));

	if (newWeapon == NULL) {
		fprintf(stderr, "Memory Allocation for weapon has failed\n");
		exit(EXIT_FAILURE);
	}
	newWeapon->name= name;
	//malloc
	newWeapon->damage = damage;
	return newWeapon;

}
//function to destroy a weapon
void destroyWeapon(WEAPON* weapon) {
	free(weapon);
}
//Function To create 3 predefined weapons and selects one weapon using random generator
WEAPON* generateRandomWeapon() {

	

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
	
	//for boundary testing 
	if (name == NULL || strlen(name) == 0 || protection < 0) {
		return NULL;  // Ensure invalid input returns NULL
	}

	ARMOUR* newArmour = (ARMOUR*)malloc(sizeof(ARMOUR));

	if (newArmour == NULL) {
		fprintf(stderr, "Memory Allocation for armour has failed\n");
		exit(EXIT_FAILURE);
	}
	newArmour->name = name;
	//malloc
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
//function is not required
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

void saveWeapon(FILE* fp, WEAPON* weapon) {
	if (weapon) {
		int weaponNameLength = strlen(weapon->name) + 1;
		fwrite(&weaponNameLength, sizeof(int), 1, fp);
		fwrite(weapon->name, sizeof(char), weaponNameLength, fp);
		fwrite(&weapon->damage, sizeof(double), 1, fp);
	}
	else
	{
		int zero = 0;
		fwrite(&zero, sizeof(int), 1, fp);
	}
}
WEAPON* loadWeapon(FILE* fp) {
	int weaponNameLength;
	fread(&weaponNameLength, sizeof(int), 1, fp);
	if (weaponNameLength > 0) {
		WEAPON* weapon = (WEAPON*)malloc(sizeof(WEAPON));
		if (!weapon) {
			fprintf(stderr, "Memory allocation fail for weapon\n");
			return NULL;
		}
		weapon->name = (char*)malloc(weaponNameLength * sizeof(char));
		if (!weapon->name) {
			fprintf(stderr, "Memory allocation fail for weapon name\n");
			free(weapon);
			return NULL;
		}
		fread(weapon->name, sizeof(char), weaponNameLength, fp);
		fread(&weapon->damage, sizeof(double), 1, fp);
		return weapon;
	}
	return NULL;
}

void saveArmour(FILE* fp, ARMOUR* armour) {
	if (armour) {
		int armourNameLength = strlen(armour->name) + 1;
		fwrite(&armourNameLength, sizeof(int), 1, fp);
		fwrite(armour->name, sizeof(char), armourNameLength, fp);
		fwrite(&armour->protection, sizeof(double), 1, fp);
	}
	else {
		int zero = 0;
		fwrite(&zero, sizeof(int), 1, fp);
	}
}
ARMOUR* loadArmour(FILE* fp) {
	int armourNameLength;
	fread(&armourNameLength, sizeof(int), 1, fp);
	if (armourNameLength > 0) {
		ARMOUR* armour = (ARMOUR*)malloc(sizeof(ARMOUR));
		if (!armour) {
			fprintf(stderr, "Memory allocation fail for armour\n");
			return NULL;
		}
		armour->name = (char*)malloc(armourNameLength * sizeof(char));
		if (!armour->name) {
			fprintf(stderr, "Memory allocation fail for armour name\n");
			free(armour);
			return NULL;
		}
		fread(armour->name, sizeof(char), armourNameLength, fp);
		fread(&armour->protection, sizeof(double), 1, fp);
		return armour;
	}
	return NULL;
}
