#include "TicTacToe.h"
#include <time.h>

TicTacToe::TicTacToe()
{
    srand(time(NULL));  // initialize random number generator

    // use random condition to determine the first player
    if (rand()>(RAND_MAX/2)) {    
        teamSide = 1;       // team blue plays first
        std::cout << "Blue team plays first." << std::endl; 
    }   
    else { 
        teamSide = -1;      // team red plays first
        std::cout << "Red team plays first." << std::endl;
    }

    std::cout << "The first player has 2 actions left." << std::endl;
    actionsLeft = 2;    // set number of actions in the first turn
    
    victory = 0;    //set victory to false
 }
