// Implementation for utils


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomNumber(int range, int floor) {
	int randomNum = rand() % range + floor;
	return randomNum;
}
