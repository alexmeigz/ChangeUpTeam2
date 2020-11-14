#include <iostream>
#include <string>
#include "TicTacToe.hpp"

TicTacToe gameBoard; //initialize game

// Validates a user-input and calls the applicable TicTacToe functions.
void checkInput(std::string input)
{

}

int main()
{
	while(gameBoard.getVictory() == 0) // Check if anyone has won.
	{
		// TODO: Replace with proper selection UI for which view the player wants to see.
		gameBoard.viewAll(); // Display game board

		if(gameBoard.getTeamSide() == 1)
			std::cout << "Your command blue! ";
		else
			std::cout << "Your command red! ";

		std::cout << "You have " << gameBoard.getActionsLeft() << " actions left in your turn." << std::endl;
		std::cout << "Remember to input a command in the format \"[ACTION] [COORD]\""
									"where [ACTION] is either \"ad\" or \"rm\" and [COORD] is a"
									"comma-separated list of integers from 0-2." << std::endl;

		std::string input;
		std::cin >> input; // "action" "X Cor" "Y Cor"; no leading space; one space between each parmater; ad stands for "add", rm stands for "remove"
		checkInput(input);
	}

	std::cout << (gameBoard.getVictory() == 1 ? "Blue" : "Red") << "wins!" << std::endl;
	return 1;
}
