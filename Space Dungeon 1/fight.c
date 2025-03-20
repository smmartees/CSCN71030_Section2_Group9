#include "fight.h"
#include "utils.h"


void displayMoves() {
    printf("\n----Choose an Action----\n");
    printf("[a] Attack\n");
    printf("[b] Block\n");
    printf("[d] Dodge\n");
    printf("[p] Take a Potion\n");
    printf("[i] Check inventory\n");
    printf("Enter Choice: ");
}

int alienMoveSelection() {
    return randomNumber(3, 1);
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
            break;
        case 2: // player attack || alien block
            reducedDamage1 = GetAlienAttack(*alien) - getArmourProtection(player);
            ReduceAlienHealth(alien, reducedDamage1);
            break;
        case 3: // player attack || alien dodge
            fiftyfifty = randomNumber(2, 1);

            if (fiftyfifty == 1){ // dodge success
                printf("The Alien successfully dodged your attack\n");
            }
            else // dodge fail
            {
                ReduceAlienHealth(alien, attack(player));
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
            reducedDamage1 = attack(player) - GetAlienDefence(*alien);
            changeHealth(player, reducedDamage1);
            break;
        case 2: // player blocks || alien blocks
            printf("You have both chosen a defensive strategy, nothing happens\n");
            break;
        case 3: // player blocks || alien dodge
            printf("While blocking the alien has tried to dodge, nothing happens\n");
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
            }
            else // dodge fail
            {
                changeHealth(player, GetAlienAttack(*alien));
            }

            break;
        case 2: // player dodges || alien blocks
            printf("While dodging the alien thought you were attack and attempted block, nothing happens\n");
            break;
        case 3: // player dodges || alien dodges
            printf("You both dodge, nothing happens\n");
            break;
        default:
            printf("The inputted alien move was not a valid int\n");
            break;
        }
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

    do {

        // print menu here
        displayMoves();
        char inputChar = getchar();
        while (getchar() != '\n');

        switch (inputChar) {
        case 'a': // attack 
            printf("Attacking Alien\n");
            calculateDamage(player, alien, ATTACK);

            break;
        case 'b': // block
            printf("Blocking Alien Attack\n");
            calculateDamage(player, alien, BLOCK);

            break;
        case 'd':// dodge
            printf("taking center door\n");
            calculateDamage(player, alien, DODGE);
            break;
        case 'p': // Take a potion
            usePotion(player);
            break;
        case 'i':
            displayPlayer(player);
            break;
        default:
            printf("Invalid option\n");
            break;
        }

        if (getHealth(player) <= 0.00 && GetAlienHealth(*alien) <= 0.00) // check if both die
        {
            printf("You and the alien have attacked at the same time and you both perish\n");
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



