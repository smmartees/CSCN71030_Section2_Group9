#pragma once
#include "player.h"
#include "loot.h"
#include "progression.h"
#include "Alien.h"
#include <stdio.h>
#include <stdbool.h>

#define ATTACK 1
#define BLOCK 2
#define DODGE 3


void displayMoves();

int alienMoveSelection();

void calculateDamage(PPLAYER player, PALIEN alien, int pMove);

bool triggerFight(PPLAYER player, PPROGRESSION prog);


