#include "TicTacToe.hpp"
#include <time.h>
#include <iostream>

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

bool TicTacToe::add(int x, int y)
{
    // if there is at least one ball to remove, remove ball from bottom of the pole
    if (field[y][x].size() > 0) {
        field[y][x].push_back(teamSide);
        actionsLeft--;
        checkVictory();

        if ((getVictory() == 0) || (actionsLeft == 0)) 
        {
            changeTurn();
        }
    }
}

bool TicTacToe::remove(int x, int y)
{
    // if there are not already three balls in the pole, add ball to top
    if (field[y][x].size() < 3) {
        field[y][x].pop_front();
        actionsLeft--;
        checkVictory();

        if ((getVictory() == 0) || (actionsLeft == 0)) 
        {
            changeTurn();
        }
    }
}