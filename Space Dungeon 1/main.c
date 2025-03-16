// Class: Project 2 - Section 2 - Text based dungeon crawler IN SPACE: SPACE SPACE
// Johan, Brodie, Sam

#include "player.h"
#include "userroominterface.h"
#include <stdio.h>


int main(void) {

	ARMOUR armour = { "Chestplate", 10.0 };
	WEAPON weapon = { "Sword", 20.0 };

	PPLAYER player = createPlayer(HEALTH_DEFAULT, armour, weapon, POTION_DEFAULT);

	roomInterface(player);



	destroyPlayer(player);
	return 0;
}