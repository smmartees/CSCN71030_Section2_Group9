// Class: Project 2 - Section 2 - Text based dungeon crawler IN SPACE: SPACE SPACE
// Johan, Brodie, Sam

#include "mainmenu.h"
#include "player.h"
#include "userroominterface.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

	srand(time(NULL));

	int n = 1; // command line argument
	int choice = mainMenu();
	if (choice == 3) {
		printf("Exiting game...\n");
		exit(EXIT_SUCCESS);
	}
	ARMOUR armour = { "Chestplate", 10.0 }; // default start armour
	WEAPON weapon = { "Sword", 20.0 }; // default start weapon
	PPLAYER player = createPlayer(HEALTH_DEFAULT, armour, weapon, POTION_DEFAULT); // default new character
	PPROGRESSION prog = initNewProg(n);

	if (choice == 2) {// load game
		bool loadCheck = loadGame(player, prog);
		if (loadCheck == false) {
			printf("There was a problem loading your game, shutting down...\n");
		}
	}
	else // new game
	{
		printf("Starting a new game...\n");
	}

	roomInterface(player, prog);

	destroyPlayer(player);
	return 0;
}