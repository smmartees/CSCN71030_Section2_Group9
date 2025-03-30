#include "mainmenu.h"

void printMainMenu() {
    printf("\n----Main Menu----\n");
    printf("[n] Start a new game\n");
    printf("[l] Load save file\n");
    printf("[q] Quit game\n");
    printf("Enter Choice: ");
}

int mainMenu() { // need to add progression module inside here as well
    // room flags
    bool quitCheck = true;
    int choice = 0;
    do {

        // print menu here
        printMainMenu();
        char inputChar = getchar();
        while (getchar() != '\n');

        switch (inputChar) {
        case 'n': // start a new game
            choice = 1; // 1 = flag to start new game
            quitCheck = false;
            break;
        case 'l': // load a save file
            printf("loading from a save file\n");
            choice = 2; // 2 = flag to load saved game
            quitCheck = false;
            break;
        case 'q': // Quit game
            quitCheck = false;
            choice = 3; // 3 = flag to quit game
            break;
        default:
            printf("Invalid option\n");
            break;
        }

    } while (quitCheck);
    return choice; // return the choice 1-3
}

//void menuChoice(PPLAYER player, int choice) {
//    if (choice == 1) { // new game
//        ARMOUR armour = { "space helmet", 10.0 }; // default values
//        WEAPON weapon = { "space sword", 20.0 }; // default values
//        PPLAYER newPlayer = createPlayer(HEALTH_DEFAULT, armour, weapon, POTION_DEFAULT);
//    }
//
//    if (choice == 2) { // load game
//        PPLAYER loadPlayer = NULL;
//        loadGame(loadPlayer);
//    }
//}