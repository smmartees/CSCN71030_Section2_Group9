// Implementation for the Alien ADT

#include <Alien.h>
#include <stdio.h>
#include <stdlib.h>



// create alien
PALIEN CreateAlien(void) {
	PALIEN newAlien = (PALIEN)malloc(sizeof(ALIEN));
	if (newAlien == NULL) {
		printf("Error creating alien!\n");
		exit(EXIT_FAILURE);
	}

}

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