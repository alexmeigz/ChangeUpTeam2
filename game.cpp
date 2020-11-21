#include <iostream>
#include <string>
#include "TicTacToe.hpp"

TicTacToe gameBoard; //initialize game

// Validates a user-input and calls the applicable TicTacToe functions.
void checkInput(std::string userInput)
{	
	using namespace std;
	int length = userInput.size();
	
	for (int i = 0; i < length; i++) { //removes spaces from userInput
		if (userInput[i] == ' ') { 
			userInput.erase(userInput.begin() + i); 
		} 
	} 

	string command = userInput.substr(0, 2); // get first 2 characters (should be ad or rm)
	string coordinates = userInput.substr(userInput.length() - 2); // get last two characters
	char xCoordinate = coordinates[0];
	char yCoordinate = coordinates[1];

	if (isdigit(xCoordinate) && isdigit(yCoordinate) && userInput.size() == 4) { //checks that the last two characters are numbers and that userInput has no other non-space characters  
		int x = (xCoordinate - '0'); //converts char to int
		int y = (yCoordinate - '0');

		if ((3 < x) || (x < 1) || (3 < y) || (y < 1)) { //checks that values of x and y are 1, 2, or 3 otherwise exits the function
			cout << "Invalid Input";
			return;
		}

		if (command == "ad") {
			if (! gameBoard.add(x - 1, y - 1)) {
				cout << "You cannot add to this stack" << endl;
			}
		}

		else if (command == "rm") { 
			if (! gameBoard.remove(x - 1, y - 1)) {
				cout << "There is nothing to remove" << endl;
			}
		} 

		else { 
			cout << "Invalid Input" << endl;
		} 
	}

	else {
		cout << "Invalid Input";
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
