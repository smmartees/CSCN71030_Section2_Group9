// Implementation for utils


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomNumber(int range, int floor) {
	int randomNum = rand() % range + floor;
	return randomNum;
}

void remove_newline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}