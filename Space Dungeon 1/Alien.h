#pragma once

// Interface for the Alien ADT


#include <stdio.h>

#define NUM_ALIEN_TYPES			3
#define ALIEN_HEALTH_FLOOR		10
#define ALIEN_HEALTH_RANGE		20
#define ALIEN_ATTACK_FLOOR		3
#define ALIEN_ATTACK_RANGE		6
#define ALIEN_DEFENCE_FLOOR		2
#define ALIEN_DEFENCE_RANGE		4

typedef struct Alien {

	double health;
	double attack;
	double defence;
	char name[50];

}ALIEN, * PALIEN;


// create alien
PALIEN CreateAlien(double diffMod);

// create alien name
char* SetAlienName(void);
// get alien name
char* GetAlienName(ALIEN alien);

// get alien health
double GetAlienHealth(ALIEN alien);

// get alien attack
double GetAlienAttack(ALIEN alien);

// get alien defence
double GetAlienDefence(ALIEN alien);

// reduce alien health (receiving damage)
void ReduceAlienHealth(PALIEN alien, double damage);

// destroy alien
void DestroyAlien(PALIEN alien);
