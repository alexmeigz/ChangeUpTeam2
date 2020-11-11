#include "TicTacToe.h"
#include <time.h>

TicTacToe::TicTacToe()
{
    srand(time(NULL));  // initialize random number generator
    int a = rand();     // generate random number
    int b = RAND_MAX / 2;   // benchmark for decision making

    // team blue plays first
    if (a > b) {    
        teamSide = 1;
        std::cout << "Blue team plays first." << std::endl;
    }   // team red plays first
    else { 
        teamSide = -1;
        std::cout << "Red team plays first." << std::endl;
    }

    std::cout << "The first player has 2 actions left." << std::endl;
    actionsLeft = 2;    // set number of actions in the first turn
 }
