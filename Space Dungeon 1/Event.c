// Interface for the Event Trigger Module


#include "Event.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// randomly determine which event
// do we need to pass the player pointer here or 
// is it called in the fight module?
int eventTrigger(void) {
	int eventType = randomNumber(2, 1);
	
	return eventType;
}

