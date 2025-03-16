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

void roomInterface(PPLAYER player) { /// need to add progression module inside here as well
    // room flags
    bool quitCheck = true;
    bool newRoomCheck = true;
    bool deathCheck = false;
    do {

        // print menu here
        displayRoomInterface();
        char inputChar = getchar();
        while (getchar() != '\n');

        switch (inputChar) {
        case 'l': // taking the left door
            // call event trigger 
            printf("taking left door\n");


            // check event type and proceed



            // check door as empty

            break;
        case 'r': // taking the right door
            // call event trigger 
            printf("taking right door\n");

            // check event type and proceed


            // check door as empty

            break;
        case 'c':// take the center door
            // call event trigger 
            printf("taking center door\n");

            // check event type and proceed


            // trigger progression flag

            break;
        case 'p': // Take a potion
            usePotion(player);
            break;
        case 'i':
            // check inventory 
            displayPlayer(player);
            break;
        case 'q': // Quit game
            quitCheck = false;
            break;
        default:
            printf("Invalid option\n");
            break;
        }

    } while (quitCheck);


    // add possible other conditions/checks here for exiting game/interface

}
