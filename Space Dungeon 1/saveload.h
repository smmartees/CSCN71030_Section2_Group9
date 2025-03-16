#pragma once
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SAVEFILE "gamesave.bin"

/// TODO: need to add progression module/struct into parameters and function definitions
bool saveGame(PPLAYER player);

PPLAYER loadGame(PPLAYER player);