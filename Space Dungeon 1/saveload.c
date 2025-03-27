#include "saveload.h"



bool saveGame(PPLAYER player, PPROGRESSION prog) {
	FILE* fp = fopen(SAVEFILE, "wb"); // Open file in binary write mode
	if (fp == NULL) {
		fprintf(stderr, "File could not be opened for saving\n");
		return false;
	}

	// Save the player structure
	fwrite(player, sizeof(PLAYER), 1, fp);

	// Save the progression structure
	fwrite(prog, sizeof(PROGRESSION), 1, fp);

	fclose(fp);
	printf("Game saved successfully!\n");
	return true;
}

bool loadGame(PPLAYER player, PPROGRESSION prog) {
	FILE* fp = fopen(SAVEFILE, "rb"); // Open file in binary read mode
	if (fp == NULL) {
		fprintf(stderr, "File could not be opened for loading\n");
		return false;
	}

	// Load the player structure
	fread(player, sizeof(PLAYER), 1, fp);

	// Load the progression structure
	fread(prog, sizeof(PROGRESSION), 1, fp);

	fclose(fp);
	printf("Game loaded successfully!\n");

	return true;
}