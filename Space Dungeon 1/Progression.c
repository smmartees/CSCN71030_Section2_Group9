// Implementation for the Progression ADT


#include "Progression.h"
#include <stdio.h>
#include <stdlib.h>



// initialize progression struct as new game
PPROGRESSION initNewProg(int modifier) {
	PPROGRESSION newProg = (PPROGRESSION)malloc(sizeof(PROGRESSION));
	if (newProg == NULL) {
		printf("Error initializing new Progress struct.\n");
		exit(EXIT_FAILURE);
	}

	newProg->progCount = 1;
	newProg->commandMod = modifier;

	SetProgMod(newProg);
	SetDiffMod(newProg);

	return newProg;
}

// load & initialize progression struct from save file
PPROGRESSION loadProg(int dungeonPosition, int modifier) {
	PPROGRESSION loadedProg = (PPROGRESSION)malloc(sizeof(PROGRESSION));
	if (loadedProg == NULL) {
		printf("Error initializing Progress struct from save file.\n");
		exit(EXIT_FAILURE);
	}

	loadedProg->progCount = dungeonPosition;
	loadedProg->commandMod = modifier;

	SetProgMod(loadedProg);
	SetDiffMod(loadedProg);

	return loadedProg;
}

// set progression count (how many rooms have they gone through)
void SetProgCount(PPROGRESSION prog, int dungeonPosition) {
	prog->progCount = dungeonPosition;
}

// set progression modifier
void SetProgMod(PPROGRESSION prog) {
	//double progressionMod = prog->progCount % 100;
	prog->progMod = 1 + ((double)prog->progCount / 100);
}

// set difficulty modifier
void SetDiffMod(PPROGRESSION prog) {
	double tempMod = (double)prog->commandMod / 100;
	prog->diffMod = prog->progMod + tempMod;
}

// increment player progression through rooms
void incrProgCount(PPROGRESSION prog) {
	prog->progCount = prog->progCount + 1;
	SetProgMod(prog);
	SetDiffMod(prog);
}
