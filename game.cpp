#include <iostream>
#include <string>

#include "TicTacToe.h" // stands for tic tac toe

int main()
{
	TicTacToe gameBoard = TicTacToe(); //initialize game
	
	//change game setting (e.g. pvp or pve)

	while("" == gameBoard.victory()) //check if anyone win
	{
		while(gameBoard.action > 0)
		{
			gameBoard.display(); //diaplay game board
			std::string input;
			std::cin >> input;
			gameBoard.play(input); //check if userInput is valid; subtract action by 1
		}
		gameBoard.changeSide() //reset action, change team tag
	}

	std::cout << gameBoard.victory() << "wins";
	return 1;
}
