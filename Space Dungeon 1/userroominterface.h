#pragma once
#include "player.h"
#include "fight.h"
#include "Event.h"
#include "saveload.h"

#define FIGHT 1
#define LOOT 2


void displayRoomInterface();

void checkWeaponSpecs(PPLAYER player, WEAPON* weapon);

void checkArmourSpecs(PPLAYER player, ARMOUR* armour);

void roomInterface(PPLAYER player, PPROGRESSION prog); 