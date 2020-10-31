#include <iostream>
#include <string>
using namespace std;

#include "TTT.h" // stands for tic tac toe

int main()
{
	TTT gameBoard = TTT(); //initialize game
	
	//change game setting (e.g. pvp or pve)

	while("" == gameBoard.victory()) //check if anyone win
	{
		while(gameBoard.action > 0)
		{
			gameBoard.display(); //diaplay game board
			string input;
			cin >> input;
			gameBoard.play(input); //check if userInput is valid; subtract action by 1
		}
		gameBoard.changeSide() //reset action, change team tag
	}

	cout << gameBoard.victory() << "wins";
	return 1;
}