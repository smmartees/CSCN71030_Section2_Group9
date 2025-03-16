#include "saveload.h"

/// TODO: need to add progression module/struct 
bool saveGame(PPLAYER player) {
	FILE* fp = fopen(SAVEFILE, "wb"); // binary mode so that the structs inside player with save together
	if (fp == NULL) {
		fprintf(stderr, "File could not be opened for saving\n");
		return false;
	}

	fwrite(player, sizeof(PLAYER), 1, fp);
	fclose(fp);
	printf("Game saved successfully!\n");
}

/// TODO: need to add progression module/struct
PPLAYER loadGame(PPLAYER player) {
	FILE* fp = fopen(SAVEFILE, "rb"); // binary read into the newPlayer so memory is in the correct location
	if (fp == NULL) {
		fprintf(stderr, "File could not be opened for loading\n");
		return NULL;
	}
	// allocate room for the saved player for loading
	PPLAYER newPlayer = (PPLAYER)malloc(sizeof(PLAYER));
	if (newPlayer == NULL) {
		fprintf(stderr, "Malloc failed during load player\n");
		fclose(fp);
		return NULL;
	}

	// load player from save file into newPlayer
	fread(newPlayer, sizeof(PLAYER), 1, fp);
	fclose(fp);
	printf("Game loaded successfully!\n");

	return newPlayer; // return saved player
}