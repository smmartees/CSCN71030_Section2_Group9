#pragma once

// Interface for the Progression ADT


typedef struct progression {
	int progCount;
	int commandMod;
	double progMod;
	double diffMod;
}PROGRESSION, * PPROGRESSION;

// initialize progression struct as new game
PPROGRESSION initNewProg(int modifier);

// load & initialize progression struct from save file
PPROGRESSION loadProg(int dungeonPosition, int modifier);

// set progression count (how many rooms have they gone through)
void SetProgCount(PPROGRESSION prog, int dungeonPosition);

// set progression modifier
void SetProgMod(PPROGRESSION prog);

// set difficulty modifier
void SetDiffMod(PPROGRESSION prog);

// increment player progression through rooms
void incrProgCount(PPROGRESSION prog);