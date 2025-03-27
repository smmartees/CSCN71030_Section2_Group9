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
	if (player->weapon) {
		int weaponNameLength = strlen(player->weapon->name) + 1;
		fwrite(&weaponNameLength, sizeof(int), 1, fp);
		fwrite(player->weapon->name, sizeof(char), weaponNameLength, fp);
		fwrite(&player->weapon->damage, sizeof(double), 1, fp);
	}
	else
	{
		int zero = 0;
		fwrite(&zero, sizeof(int), 1, fp);
	}

	/// Save armour
	if (player->armour) {
		int armourNameLength = strlen(player->armour->name) + 1;
		fwrite(&armourNameLength, sizeof(int), 1, fp);
		fwrite(player->armour->name, sizeof(char), armourNameLength, fp);
		fwrite(&player->armour->protection, sizeof(double), 1, fp);
	}
	else {
		int zero = 0;
		fwrite(&zero, sizeof(int), 1, fp);
	}



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
	int weaponNameLength;
	fread(&weaponNameLength, sizeof(int), 1, fp);
	if (weaponNameLength > 0) {
		player->weapon = (WEAPON*)malloc(sizeof(WEAPON));
		if (!player->weapon) {
			fprintf(stderr, "Memory allocation fail for weapon\n");
			fclose(fp);
			return false;
		}
		player->weapon->name = (char*)malloc(weaponNameLength * sizeof(char));
		if (!player->weapon->name) {
			fprintf(stderr, "Memory allocation fail for weapon name\n");
			fclose(fp);
			return false;
		}
		fread(player->weapon->name, sizeof(char), weaponNameLength, fp);
		fread(&player->weapon->damage, sizeof(double), 1, fp);
	}
	else
	{
		player->weapon = NULL;
;	}

	/// Load armour
	int armourNameLength;
	fread(&armourNameLength, sizeof(int), 1, fp);
	if (armourNameLength > 0) {
		player->armour = (ARMOUR*)malloc(sizeof(ARMOUR));
		if (!player->armour) {
			fprintf(stderr, "Memory allocation fail for armour\n");
			fclose(fp);
			return false;
		}
		player->armour->name = (char*)malloc(armourNameLength * sizeof(char));
		if (!player->armour->name) {
			fprintf(stderr, "Memory allocation fail for armour name\n");
			fclose(fp);
			return false;
		}
		fread(player->armour->name, sizeof(char), armourNameLength, fp);
		fread(&player->armour->protection, sizeof(double), 1, fp);
	}
	else {
		player->armour = NULL;
	}

	fclose(fp);
	printf("Game loaded successfully!\n");

	return true;
}