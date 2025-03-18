#define _CRT_SECURE_NO_WARNINGS

// Implementation for the Alien ADT

#include "Alien.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// create alien
PALIEN CreateAlien(double diffMod) {
	PALIEN newAlien = (PALIEN)malloc(sizeof(ALIEN));
	if (newAlien == NULL) {
		printf("Error creating alien!\n");
		exit(EXIT_FAILURE);
	}

	// setting alien name
	strcpy(newAlien->name, SetAlienName());

	// setting alien health
	int baseHealth = randomNumber(ALIEN_HEALTH_RANGE, ALIEN_HEALTH_FLOOR);
	newAlien->health = (double)baseHealth * diffMod;

	// setting alien attack
	int baseAttack = randomNumber(ALIEN_ATTACK_RANGE, ALIEN_ATTACK_FLOOR);
	newAlien->attack = (double)baseAttack * diffMod;

	// setting alien defence
	int baseDefence = randomNumber(ALIEN_DEFENCE_RANGE, ALIEN_DEFENCE_FLOOR);
	newAlien->defence = (double)baseDefence * diffMod;

}

// create alien name
char* SetAlienName(void) {
	int prefixNum = randomNumber(NUM_ALIEN_TYPES, LIST_FLOOR);
	int nameNum = randomNumber(NUM_ALIEN_TYPES, LIST_FLOOR);

	char* completeAlienName = "\0";
	char* alienName = "\0";
	char* alienPrefix = "\0";

	/*char alienName[3][3] = {
		{"Xenomorph ", "Pirate "},
		{"Dirty ", "Grotesque ", "Unfathomable "},

	};

	alienName[0][0] = "pistol";
	alienName[0][1] = "rifle";
	alienName[0][2] = "smg";
	alienName[1][0] = "shank";
	alienName[1][1] = "sword";*/

	switch (prefixNum)
	{
	case 1:
		alienPrefix = "Dirty ";
		break;
	case 2:
		alienPrefix = "Grotesque ";
		break;
	case 3:
		alienPrefix = "Unfathomable ";
		break;
	default:
		break;
	}

	switch (nameNum)
	{
	case 1:
		alienName = "Space Xenomorph";
		break;
	case 2:
		alienName = "Space Pirate";
		break;
	case 3:
		alienName = "Space Kracken";
		break;
	default:
		break;
	}

	strcat(alienPrefix, alienName);
	
	return alienPrefix;
}

// get alien health
double GetAlienHealth(ALIEN alien) {
	return alien.health;
}

// get alien attack
double GetAlienAttack(ALIEN alien) {
	return alien.attack;
}

// get alien defence
double GetAlienDefence(ALIEN alien) {
	return alien.defence;
}

// get alien name
char* GetAlienName(ALIEN alien) {
	return alien.name;
}

// reduce alien health (receiving damage)
void ReduceAlienHealth(PALIEN alien, double damage) {
	alien->health -= damage;
}

// destroy alien
void DestroyAlien(PALIEN alien) {
	free(alien);
}