#pragma once

// Interface for the Alien ADT


#include <stdio.h>



typedef struct Alien {
	
	double health;
	double attack;
	double defence;
	char* name;

}ALIEN, *PALIEN;


// create alien
PALIEN CreateAlien(void);

// get alien health
double GetAlienHealth(ALIEN alien);

// get alien attack
double GetAlienAttack(ALIEN alien);

// get alien defence
double GetAlienDefence(ALIEN alien);

// get alien name
char* GetAlienName(ALIEN alien);

// reduce alien health (receiving damage)
void ReduceAlienHealth(PALIEN alien);

// destroy alien
void DestroyAlien(PALIEN alien);
