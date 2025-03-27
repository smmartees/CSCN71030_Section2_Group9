#pragma once
#include "player.h"
#include "Progression.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SAVEFILE "gamesave.bin"


bool saveGame(PPLAYER player, PPROGRESSION prog);
bool loadGame(PPLAYER player, PPROGRESSION prog);
