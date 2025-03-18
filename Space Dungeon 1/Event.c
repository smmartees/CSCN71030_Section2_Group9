// Interface for the Event Trigger Module


#include "Event.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// randomly determine which event
// do we need to pass the player pointer here or 
// is it called in the fight module?
void eventTrigger(PROGRESSION prog, PPLAYER player) {
	int eventType = randomNumber(2, 1);

	switch (eventType)
	{
	case 1:
		// fight module
		break;
	case 2:
		// loot module
		break;
	default:
		printf("Error triggering event type.\n");
		break;
	}
}

// trigger fight event
//void fightEvent(PROGRESSION prog, PPLAYER player);

// trigger loot event
//void lootEvent(PROGRESSION prog, PPLAYER player);
