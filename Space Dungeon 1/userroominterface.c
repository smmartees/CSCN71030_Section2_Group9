#include "userroominterface.h"
#include "player.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>

void displayRoomInterface() {
    printf("\n----Choose your next action----\n");
    printf("[l] take the left door\n");
    printf("[r] take the right door\n");
    printf("[c] take the center door\n");
    printf("[p] take a health potion\n");
    printf("[i] check your inventory\n");
    printf("[m] show progress\n");
    printf("[s] save Game\n");
    printf("[q] Quit game\n");
    printf("Enter Choice: ");
}

void checkWeaponSpecs(PPLAYER player, WEAPON* weapon) {
    if (weapon->damage < player->weapon->damage) {
        weapon->damage = player->weapon->damage;
    }
}

void checkArmourSpecs(PPLAYER player, ARMOUR* armour) {
    if (armour->protection < player->armour->protection) {
        armour->protection = player->armour->protection;
    }
}

void roomInterface(PPLAYER player, PPROGRESSION prog) {
    // room flags
    bool quitCheck = true;
    bool newRoomCheck = true;
    bool deathCheck = false;
    int eventType;
    int winnerCheck;
    do {

        // print menu here
        displayRoomInterface();
        char inputChar = getchar();
        while (getchar() != '\n');

        switch (inputChar) {
        case 'l': // taking the left door
            // call event trigger 
            printf("\n----Taking left door----\n");
            eventType = eventTrigger();

            if (eventType == LOOT) {
                // give the player loot
                printf("\nYou have found loot in this room...\n");
                int lootType = randomNumber(3, 1);
                if (lootType == 1) {
                    ARMOUR* newArmour = generateRandomArmour(prog->diffMod);
                    checkArmourSpecs(player, newArmour);
                    changeArmour(player, newArmour);
                    printf("you have recieved a %s with %.2f protection\n", newArmour->name, newArmour->protection);
                }
                else if (lootType == 2)
                {
                    WEAPON* newWeapon = generateRandomWeapon(prog->diffMod);
                    checkWeaponSpecs(player, newWeapon);
                    changeWeapon(player, newWeapon);
                    printf("you have recieved a %s with %.2f damage\n", newWeapon->name, newWeapon->damage);
                }
                else
                {
                    printf("You have recieved a potion\n");
                    addPotion(player);
                }
                incrProgCount(prog);
            }
            else if (eventType == FIGHT) {
                printf("You have encountered a space alien in this room...\n");
                winnerCheck = triggerFight(player, prog);
                if (winnerCheck == true) {
                    printf("You have Won the Fight!\n");
                    incrProgCount(prog);
                }
                else
                {
                    deathCheck = true;
                }
            }
            else {
                printf("There has been an triggering the event type\n");
            }

            break;
        case 'r': // taking the right door
            // call event trigger 
            printf("\n----Taking right door----\n");
            eventType = eventTrigger();

            if (eventType == LOOT) {
                // give the player loot
                printf("\nYou have found loot in this room...\n");
                int lootType = randomNumber(3, 1);
                if (lootType == 1) {
                    ARMOUR* newArmour = generateRandomArmour(prog->diffMod);
                    checkArmourSpecs(player, newArmour);
                    changeArmour(player, newArmour);
                    printf("you have recieved a %s with %.2f protection\n", newArmour->name, newArmour->protection);
                }
                else if (lootType == 2)
                {
                    WEAPON* newWeapon = generateRandomWeapon(prog->diffMod);
                    checkWeaponSpecs(player, newWeapon);
                    changeWeapon(player, newWeapon);
                    printf("you have recieved a %s with %.2f damage\n", newWeapon->name, newWeapon->damage);
                }
                else
                {
                    printf("You have recieved a potion\n");
                    addPotion(player);
                }
                incrProgCount(prog);
            }
            else if (eventType == FIGHT) {
                printf("You have encountered a space alien in this room...\n");
                winnerCheck = triggerFight(player, prog);
                if (winnerCheck == true) {
                    printf("You have Won the Fight!\n");
                    incrProgCount(prog);
                }
                else
                {
                    deathCheck = true;
                }
            }
            else {
                printf("There has been an triggering the event type\n");
            }

            break;
        case 'c':// take the center door
            // call event trigger 
            printf("\n----Taking center door----\n");
            eventType = eventTrigger();

            if (eventType == LOOT) {
                // give the player loot
                printf("\nYou have found loot in this room...\n");
                int lootType = randomNumber(3, 1);
                if (lootType == 1) {
                    ARMOUR* newArmour = generateRandomArmour(prog->diffMod);
                    checkArmourSpecs(player, newArmour);
                    changeArmour(player, newArmour);
                    printf("you have recieved a %s with %.2f protection\n", newArmour->name, newArmour->protection);
                }
                else if (lootType == 2)
                {
                    WEAPON* newWeapon = generateRandomWeapon(prog->diffMod);
                    checkWeaponSpecs(player, newWeapon);
                    changeWeapon(player, newWeapon);
                    printf("you have recieved a %s with %.2f damage\n", newWeapon->name, newWeapon->damage);
                }
                else
                {
                    printf("You have recieved a potion\n");
                    addPotion(player);
                }
                incrProgCount(prog);
            }
            else if (eventType == FIGHT) {
                printf("You have encountered a space alien in this room...\n");
                winnerCheck = triggerFight(player, prog);
                if (winnerCheck == true) {
                    printf("You have Won the Fight!\n");
                    incrProgCount(prog);
                }
                else
                {
                    deathCheck = true;
                }
            }
            else {
                printf("There has been an triggering the event type\n");
            }

            break;
        case 'p': // Take a potion
            usePotion(player);
            break;
        case 'i':
            // check inventory 
            displayPlayer(player);
            break;
        case 'm': // display progress
            printf("\n");
            printLocation(*prog);
            break;
        case 's': //save game
            saveGame(player, prog, SAVEFILE);
            break;
        case 'q': // Quit game
            quitCheck = false;
            saveGame(player, prog, SAVEFILE);
            break;
        default:
            printf("Invalid option\n");
            break;
        }

        if (deathCheck == true) {
            quitCheck = false;
            printf("YOU DIED!\n");
        }

    } while (quitCheck);

}
