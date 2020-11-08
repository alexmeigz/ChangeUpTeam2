#include <iostream>
#include <string>
#include "TicTacToe.h"

TicTacToe gameBoard = TicTacToe(); //initialize game

// Validates a user-input and calls the applicable TicTacToe functions.
void checkInput(std::string input)
{

}

int main()
{
	while(0 == gameBoard.getVictory()) //check if anyone win; 0 means nobody wins
	{
		gameBoard.display(); //diaplay game board
		if(1 == gameBoard.getTeamSide())
		{
			std::cout << "Your command blue" << endl;
		}
		else
		{
			std::cout << "Your command red" << endl;
		}

		std::string input;
		std::cin >> input; // "action" "X Cor" "Y Cor"; no leading space; one space between each parmater; ad stands for "add", re stands for "remove"
		checkInput(input); //check if userInput is valid; subtract action by 1
	}

	std::cout << gameBoard.victory() << "wins";
	return 1;
}
