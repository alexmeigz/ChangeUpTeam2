#include "TicTacToe.hpp"
#include <time.h>
#include <iostream>

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


void TicTacToe::viewAll()
{
	// Prints out the field with relevant team integers
	std::cout << "    " << field[2][0][2] << " --- " << field[2][1][2] << " --- " << field[2][2][2] << std::endl;
	std::cout << "   /     /     /|" << std::endl;
	std::cout << "  " << field[1][0][2] << " --- " << field[1][1][2] << " --- " << field[1][2][2] << " |" << std::endl;
	std::cout << " /     /     /  |" << std::endl;
	std::cout << field[0][0][2] << " --- " << field[0][1][2] << " --- " << field[0][2][2] << "   |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|   " << field[2][0][1] << " --- " << field[2][1][1] << " --- " << field[2][2][1] << std::endl;
	std::cout << "|  /     /     /|" << std::endl;
	std::cout << "| " << field[1][0][1] << " --- " << field[1][1][1] << " --- " << field[1][2][1] << " |" << std::endl;
	std::cout << "|/     /     /  |" << std::endl;
	std::cout << field[0][0][1] << " --- " << field[0][1][1] << " --- " << field[0][2][1] << "   |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|   " << field[2][0][0] << " --- " << field[2][1][0] << " --- " << field[2][2][0] << std::endl;
	std::cout << "|  /     /     / " << std::endl;
	std::cout << "| " << field[1][0][0] << " --- " << field[1][1][0] << " --- " << field[1][2][0] << "  " << std::endl;
	std::cout << "|/     /     /   " << std::endl;
	std::cout << field[0][0][0] << " --- " << field[0][1][0] << " --- " << field[0][2][0] << "    " << std::endl;
}

void TicTacToe::viewTop() {
 	   for (int y = 2; y >= 0; y--) {
        for (int x = 0; x < 3; x++) {
            std::deque<int> square = field[y][x];
            int size = square.size();
						int value = square[2]; // will be 1 (blue) or -1 (red) or 0 (empty)
						if (value == 1){
								std::cout << "b";
						}
						else if (value == -1) {
								std::cout << "r";
						}
						else if (value == 0) {
							std::cout << "x";
						}
            else {
							std::cout << "?";
						}  

            
            std::cout << " ";
        }
        std::cout << "\n";
    }
}