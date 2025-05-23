#include "fight.h"
#include "utils.h"
#include <math.h>

void displayMoves() {
    printf("\n----Choose an Action----\n");
    printf("[a] Attack\n");
    printf("[b] Block\n");
    printf("[d] Dodge\n");
    printf("[p] Take a Potion\n");
    printf("[i] Check inventory\n");
    printf("[o] Display Alien Stats\n");
    printf("Enter Choice: ");
}

int alienMoveSelection() {
    return randomNumber(3, 1);
}

void displayHealthNumbers(PPLAYER player, PALIEN alien) {
    printf("\n----Remaining Health----\n");
    printf("Player Health: [%.2f]\n", player->health);
    printf("Alien Health: [%.2f]\n", alien->health);
}

void displayCurrentAlien(PALIEN alien) {
    printf("\n----%s----\n", alien->name);
    printf("Alien Health: %.2f\n", alien->health);
    printf("Alien Attack: %.2f\n", alien->attack);
    printf("Alien Defence: %.2f\n", alien->defence);
}

// calculate the damage being inflicted and then distribute to the player/alien
void calculateDamage(PPLAYER player, PALIEN alien, int pMove) {
    int aMove = alienMoveSelection();
    double reducedDamage1;
    double reducedDamage2;
    int fiftyfifty;
    switch (pMove)
    {
    case 1:

        switch (aMove)
        {
        case 1: // player attack || alien attack 
            changeHealth(player, GetAlienAttack(*alien));
            ReduceAlienHealth(alien, attack(player));
            printf("You both attack\n");
            AlienContextHealth(*alien);
            displayHealthNumbers(player, alien);
            break;
        case 2: // player attack || alien block
            reducedDamage1 = fmax(0.00, attack(player) - GetAlienDefence(*alien));
            ReduceAlienHealth(alien, reducedDamage1);
            printf("You attack, alien blocks\n");
            AlienContextHealth(*alien);
            displayHealthNumbers(player, alien);
            break;
        case 3: // player attack || alien dodge
            fiftyfifty = randomNumber(2, 1);
            printf("You attack, alien dodges\n");
            if (fiftyfifty == 1){ // dodge success
                printf("The Alien successfully dodged your attack\n");
                displayHealthNumbers(player, alien);
            }
            else // dodge fail
            {
                ReduceAlienHealth(alien, attack(player));
                printf("The alien failed to dodge your attack\n");
                AlienContextHealth(*alien);
                displayHealthNumbers(player, alien);
            }

            break;
        default:
            printf("The inputted alien move was not a valid int\n");
            break;
        }


        break;
    case 2:
        // player blocks 

        switch (aMove)
        {
        case 1:// player blocks || alien attacks
            reducedDamage1 = fmax(0.00, GetAlienAttack(*alien) - getArmourProtection(player));
            changeHealth(player, reducedDamage1);
            printf("You block, alien attacks\n");
            displayHealthNumbers(player, alien);
            break;
        case 2: // player blocks || alien blocks
            printf("You have both chosen a defensive strategy, nothing happens\n");
            displayHealthNumbers(player, alien);
            break;
        case 3: // player blocks || alien dodge
            printf("While blocking the alien has tried to dodge, nothing happens\n");
            displayHealthNumbers(player, alien);
            break;
        default:
            printf("The inputted alien move was not a valid int\n");
            break;
        }

        break;
    case 3:
        // player dodges

        switch (aMove)
        {
        case 1: // player dodges || alien attacks
            fiftyfifty = randomNumber(2, 1);

            if (fiftyfifty == 1) { // dodge success
                printf("You have successfully dodged the alien's attack\n");
                displayHealthNumbers(player, alien);
            }
            else // dodge fail
            {
                changeHealth(player, GetAlienAttack(*alien));
                printf("You failed to dodge alien attack\n");
                displayHealthNumbers(player, alien);
            }

            break;
        case 2: // player dodges || alien blocks
            printf("While dodging, the alien thought you were attack and attempted block\nNothing happens...\n");
            displayHealthNumbers(player, alien);
            break;
        case 3: // player dodges || alien dodges
            printf("You both dodge, nothing happens\n");
            displayHealthNumbers(player, alien);
            break;
        default:
            printf("The inputted alien move was not a valid int\n");
            break;
        }
        break;
    default:
        printf("The inputted player move was not a valid int\n");
        break;
    }
}

bool triggerFight(PPLAYER player, PPROGRESSION prog) {
    bool quitCheck = true;
    bool playerWin;

    // generate alien here
    PALIEN alien = CreateAlien(prog->diffMod);
    printf("\n");
    AlienContextAttack(*alien);
    AlienContextDefense(*alien);
    displayCurrentAlien(alien);
    do {

        // print menu here
        displayMoves();
        char inputChar = getchar();
        while (getchar() != '\n');

        switch (inputChar) {
        case 'a': // attack 
            printf("Attacking Alien...\n\n");
            printf("----Result----\n");
            calculateDamage(player, alien, ATTACK);
            break;
        case 'b': // block
            printf("Blocking Alien Attack...\n\n");
            printf("----Result----\n");
            calculateDamage(player, alien, BLOCK);
            break;
        case 'd':// dodge
            printf("Dodging...\n\n");
            printf("----Result----\n");
            calculateDamage(player, alien, DODGE);
            break;
        case 'p': // Take a potion
            usePotion(player);
            break;
        case 'i':
            displayPlayer(player);
            break;
        case 'o':
            displayCurrentAlien(alien);
            break;
        default:
            printf("Invalid option\n");
            break;
        }

        if (getHealth(player) <= 0.00 && GetAlienHealth(*alien) <= 0.00) // check if both die
        {
            printf("You and the alien have attacked at the same time and you both perish\n");
            printf("That sucks...\n");
            playerWin = false;
            quitCheck = false;
            DestroyAlien(alien);
        }
        else if (getHealth(player) <= 0.00) { // player died & lost
            playerWin = false;
            quitCheck = false;
            DestroyAlien(alien);
        }
        else if (GetAlienHealth(*alien) <= 0.00) // player wins 
        {
            playerWin = true;
            quitCheck = false;
            DestroyAlien(alien);
        }

    } while (quitCheck);

    return playerWin;
}



