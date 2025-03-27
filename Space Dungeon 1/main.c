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

	// seed for game randomization events
	srand(time(NULL));

	int n = 1; // command line argument
	int choice = mainMenu();
	if (choice == 3) {
		printf("Exiting game...\n");
		exit(EXIT_SUCCESS);
	}
	// Game Defaults
	ARMOUR* armour = createArmour("Helmet", 15.00); // default start armour
	WEAPON* weapon = createWeapon("Axe", 20.00); // default start weapon
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

	// deallocate memory 
	/// could add some destroying functions to the following items
	free(prog);
	free(player->weapon); /// can't free weapon/armour names, as they have not been allocated properly. 
	free(player->armour); /// need to allocate memory to the names within the loot module (createArmour/createWeapon functions (malloc the names)) 
	destroyPlayer(player); /// can add the frees into destroy player after fixing createArmour/createWeapon
	return 0;
}