#include <deque>

class TicTacToe
{
	public:
		TicTacToe(); // Vedad
		void checkVictory();
		int getVictory();

		void viewAll();
		void viewTop();
		void viewSide(int side); // int represent which side to look at

		bool add(int x, int y); // Anushka
		bool remove(int x, int y); // Anushka

		int getActionLeft(); // Minh
		int getTeamSide(); // Minh
		void changeSide(); //Phillip

	private:
		// Stores the state of the game board
		// * Index 0 is the bottom and index 2 is top of each stack.
		std::deque<int> field[3][3];
		// Flag determining whose turn it is:
		// * 1 is the blue alliance
		// * -1 is the red alliance
		// * 0 is for when the game is over and someone has won
		int teamSide;
		// Decrementing counter for keeping track of how many actions are left in
		// the player's turn.
		int actionLeft;
};
