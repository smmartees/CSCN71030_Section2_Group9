#include "player.h"
#include <stdio.h>
#include <stdlib.h>

// Player function definitions

PPLAYER createPlayer(double health, ARMOUR* armour, WEAPON* weapon, int potions) {
	PPLAYER newPlayer = (PPLAYER)malloc(sizeof(PLAYER));
	if (newPlayer == NULL) { // check for malloc failure
		fprintf(stderr, "Malloc failed to allocate\n");
		exit(EXIT_FAILURE);
	}
	// set player values
	newPlayer->health = health;
	newPlayer->armour = armour;
	newPlayer->weapon = weapon;
	newPlayer->potions = potions;

	return newPlayer;
}

void changeHealth(PPLAYER player, double damage) {
	player->health -= damage;
}

void changeArmour(PPLAYER player, ARMOUR* armour) {
	if (player->armour) {
		free(player->armour);  // Free the old weapon if it was dynamically allocated
	}
	player->armour = armour;
}

void changeWeapon(PPLAYER player, WEAPON* weapon) {
	if (player->weapon) {
		free(player->weapon);  // Free the old weapon if it was dynamically allocated
	}
	player->weapon = weapon;
}

void addPotion(PPLAYER player) {
	player->potions++;
}

void usePotion(PPLAYER player) {
	if (player->potions == 0) {
		printf("\nYou do not have any potions\n");
		return;
	}
	if (player->health == 100.0) {
		printf("\nyour health is already full\n");
		return;
	}
	printf("\nYour health has been restored\n");
	player->health = 100.0;
	player->potions--;
}

double getHealth(PPLAYER player) {
	return player->health;
}

char* getWeaponName(PPLAYER player) {
	return player->weapon->name;
}

char* getArmourName(PPLAYER player) {
	return player->armour->name;
}

double getArmourProtection(PPLAYER player) {
	return player->armour->protection;
}

int getPotionCount(PPLAYER player) {
	return player->potions;
}

double attack(PPLAYER player) {
	return player->weapon->damage;
}


void displayPlayer(PPLAYER player) {
	printf("\n--------Player Stats-----------\n");
	printf("HEALTH: [%.2f]\n", getHealth(player));
	printf("Weapon: %s, Damage: [%.2f]\n", getWeaponName(player), attack(player));
	printf("Armour: %s, Protection: [%.2f]\n", getArmourName(player), getArmourProtection(player));
	printf("Potions: %d\n", getPotionCount(player));
	printf("-------------------------------\n");
}

void destroyPlayer(PPLAYER player) {
	destroyArmour(player->armour);
	destroyWeapon(player->weapon);
	free(player);
}