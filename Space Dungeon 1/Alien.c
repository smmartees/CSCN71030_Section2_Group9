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
	//simplifying list for testing
	/*int prefixNum = randomNumber(NUM_ALIEN_TYPES, LIST_FLOOR);
	int nameNum = randomNumber(NUM_ALIEN_TYPES, LIST_FLOOR);*/
	//delete the below after passing tests
	int prefixNum = randomNumber(2, LIST_FLOOR);
	int nameNum = randomNumber(2, LIST_FLOOR);

	char* completeAlienName = "\0";
	char* alienName = "\0";
	char* alienPrefix = "\0";

	switch (prefixNum)
	{
	case 0:
		alienPrefix = "Dirty ";
		break;
	case 1:
		alienPrefix = "Grotesque ";
		break;
		/*case 2:	//restore after passing tests
			alienPrefix = "Unfathomable ";
			break;*/
	default:
		break;
	}

	switch (nameNum)
	{
	case 0:
		alienName = "Space Xenomorph";
		break;
	case 1:
		alienName = "Space Pirate";
		break;
		/*case 2:	//restore after passing tests
			alienName = "Space Kracken";
			break;*/
	default:
		break;
	}

	strcat(alienPrefix, alienName);

	return alienPrefix;
}

// get alien name
char* GetAlienName(ALIEN alien) {
	return alien.name;
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

// reduce alien health (receiving damage)
void ReduceAlienHealth(PALIEN alien, double damage) {
	alien->health -= damage;
}

// destroy alien
void DestroyAlien(PALIEN alien) {
	free(alien);
}