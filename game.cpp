#include <iostream>
#include <string>
#include "TicTacToe.hpp"

TicTacToe gameBoard; //initialize game

// Validates a user-input and calls the applicable TicTacToe functions.
void checkInput(std::string userInput)
{	
	using namespace std;
	char command = userInput[0];
	int x = userInput[1] - '0';
	int y = userInput[2] - '0';

	if((3 < x) || (x < 1) || (3 < y) || (y < 1)) { //checks that values of x and y are 1, 2, or 3 otherwise exits the function
		cout << "cordinate out of range";
		return;
	}

	if(command == 'a') {
		if(!gameBoard.add(x - 1, y - 1)) {
			cout << "You cannot add to this stack" << endl;
		}
	}
	else if(command == 'r') {
		if(!gameBoard.remove(x - 1, y - 1)) {
			cout << "There is nothing to remove" << endl;
		}
	}
	else {
		cout << "Unkown command" << endl;
	}
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

		std::string input;
		std::cin >> input; // "action" "X Cor" "Y Cor"; no leading space; one space between each parmater; ad stands for "add", rm stands for "remove"
		checkInput(input);
	}

	std::cout << (gameBoard.getVictory() == 1 ? "Blue" : "Red") << "wins!" << std::endl;
	return 1;
}
