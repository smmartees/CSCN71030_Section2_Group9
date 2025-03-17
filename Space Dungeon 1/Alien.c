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
	strcpy(newAlien->name, CreateAlienName());

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
	int nameNum = randomNumber(NUM_ALIEN_TYPES, LIST_FLOOR);
	char* alienName;

	switch (nameNum)
	{
	case 1:
		alienName = "Xenomorph";
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
	
	return alienName;
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