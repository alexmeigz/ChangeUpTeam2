#include "TicTacToe.hpp"
#include <time.h>

TicTacToe::TicTacToe()
{
    srand(time(NULL));  // initialize random number generator

    // use random condition to determine the first player
    if (rand()>(RAND_MAX/2)) {
        teamSide = 1;       // team blue plays first
    } else {
        teamSide = -1;      // team red plays first
    }

    actionsLeft = 2;    // set number of actions in the first turn
    victory = 0;    //set victory to false
 }

bool TicTacToe::add(int x, int y)
{
    // if there are not already three balls in the pole, add ball to top
    if (field[y][x].size() < 3) {
        field[y][x].push_back(teamSide);
        actionsLeft--;
        checkVictory();

        if ((getVictory() == 0) && (actionsLeft == 0))
        {
            changeTurn();
        }

        return true;
    } else return false;
}

bool TicTacToe::remove(int x, int y)
{
    // if there is at least one ball to remove, remove ball from bottom of the pole
    if (field[y][x].size() > 0) {
        field[y][x].pop_front();
        actionsLeft--;
        checkVictory();

        if ((getVictory() == 0) && (actionsLeft == 0))
        {
            changeTurn();
        }

        return true;
    } else return false;
}

int TicTacToe::checkVictoryHorizontal(int teamSide)
{
    int point = 0;
    for(int y = 0; y <= 2; y = y + 1){
      for(int z = 0; z < field[y][0].size(); z = z + 1){
        if(field[y][0][z] == teamSide){
          if(field[y][1].size() >= (z + 1) && field[y][1][z] == teamSide){
            if(field[y][2].size() >= (z + 1) && field[y][2][z] == teamSide){
              point = point + 1;
            }
          }
        }
      }
    }
    for(int x = 0; x <= 2; x = x + 1){
      for(int z = 0; z < field[0][x].size(); z = z + 1){
        if(field[0][x][z] == teamSide){
          if(field[1][x].size() >= (z + 1) && field[1][x][z] == teamSide){
            if(field[2][x].size() >= (z + 1) && field[2][x][z] == teamSide){
              point = point + 1;
            }
          }
        }
      }
    }
    return point;
}
