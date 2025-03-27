#include "userroominterface.h"
#include "player.h"
#include <stdio.h>
#include <stdbool.h>

void displayRoomInterface() {
    printf("\n----Choose your next action----\n");
    printf("[l] take the left door\n");
    printf("[r] take the right door\n");
    printf("[c] take the center door\n");
    printf("[p] take a health potion\n");
    printf("[i] check your inventory\n");
    printf("[q] Quit game\n");
    printf("Enter Choice: ");
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
            printf("taking left door\n");
            eventType = eventTrigger();

            if (eventType == LOOT) {
                // give the player loot
                printf("Got loot\n");///NEED TO ADD THE GETTING LOOT FUNCTION HERE
                incrProgCount(prog);
            }
            else if (eventType == FIGHT) {
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
            printf("taking left door\n");
            eventType = eventTrigger();

            if (eventType == LOOT) {
                // give the player loot
                printf("Got loot\n");///NEED TO ADD THE GETTING LOOT FUNCTION HERE
                incrProgCount(prog);
            }
            else if (eventType == FIGHT) {
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
            printf("taking left door\n");
            eventType = eventTrigger();

            if (eventType == LOOT) {
                // give the player loot
                printf("Got loot\n");///NEED TO ADD THE GETTING LOOT FUNCTION HERE
                incrProgCount(prog);
            }
            else if (eventType == FIGHT) {
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
        case 's': //save game
            saveGame(player, prog);
            break;
        case 'q': // Quit game
            quitCheck = false;/// TODO: add save case for saving without quitting
            saveGame(player, prog);
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
