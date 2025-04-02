#include "saveload.h"



bool saveGame(PPLAYER player, PPROGRESSION prog, char* fileName) {
	FILE* fp = fopen(fileName, "wb"); // Open file in binary write mode
	if (fp == NULL) {
		fprintf(stderr, "File could not be opened for saving\n");
		return false;
	}

	// Save the player structure
	fwrite(player, sizeof(PLAYER), 1, fp);

	// Save the progression structure
	fwrite(prog, sizeof(PROGRESSION), 1, fp);

	/// saving weapon
	saveWeapon(fp, player->weapon);

	/// Save armour
	saveArmour(fp, player->armour);



	fclose(fp);
	printf("Game saved successfully!\n");
	return true;
}

bool loadGame(PPLAYER player, PPROGRESSION prog, char* fileName) {
	FILE* fp = fopen(fileName, "rb"); // Open file in binary read mode
	if (fp == NULL) {
		fprintf(stderr, "File could not be opened for loading\n");
		return false;
	}

	// Load the player structure
	fread(player, sizeof(PLAYER), 1, fp);

	// Load the progression structure
	fread(prog, sizeof(PROGRESSION), 1, fp);

	/// load weapon
	player->weapon = loadWeapon(fp);

	/// Load armour
	player->armour = loadArmour(fp);

	fclose(fp);
	printf("Game loaded successfully!\n");

	return true;
}