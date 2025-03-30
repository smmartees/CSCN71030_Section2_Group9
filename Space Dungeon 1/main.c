// Class: Project 2 - Section 2 - Text based dungeon crawler IN SPACE: SPACE SPACE
// Johan, Brodie, Sam

#include "mainmenu.h"
#include "player.h"
#include "userroominterface.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_DAMAGE 10.00
#define DEFAULT_ARMOUR 5.00

int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("This program only accepts a single argument\n");
		return 1;
	}
	
	int n = atoi(argv[1]);

	printf("Difficulty: %d\n", n);

	// seed for game randomization events
	srand(time(NULL));

	int choice = mainMenu();
	if (choice == 3) {
		printf("Exiting game...\n");
		exit(EXIT_SUCCESS);
	}
	// Game Defaults
	ARMOUR* armour = createArmour("Helmet", DEFAULT_ARMOUR); // default start armour
	WEAPON* weapon = createWeapon("Axe", DEFAULT_DAMAGE); // default start weapon
	PPLAYER player = createPlayer(HEALTH_DEFAULT, armour, weapon, POTION_DEFAULT); // default new character
	PPROGRESSION prog = initNewProg(n);

	if (choice == 2) {// load game
		bool loadCheck = loadGame(player, prog, SAVEFILE);
		if (loadCheck == false) {
			printf("There was a problem loading your game, shutting down...\n");
			exit(EXIT_FAILURE);
		}
	}
	else // new game
	{
		printf("Starting a new game...\n");
	}

	// Enter the game
	roomInterface(player, prog);

	free(prog);
	destroyPlayer(player); 
	return 0;
}