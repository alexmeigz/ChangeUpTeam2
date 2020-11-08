#include <deque>

class TicTacToe
{
	public:
		TicTacToe(); // Vedad

		// Prints different ASCII-art-esque maps of the game board.
		void viewAll();
		void viewTop();
		void viewSide(int side); // int represents which side to look at

		// These functions add/remove a ball from the field and:
		// * Decrement actionsLeft
		// * Call checkVictory()
		// * IF victory == 0 AND actionsLeft == 0
		//   * Call changeTurn()
		bool add(int x, int y); // Anushka
		bool remove(int x, int y); // Anushka

		int getActionsLeft(); // Minh
		int getTeamSide(); // Minh
		int getVictory();

	private:
		// These functions should only be called from within this class.
		void changeTurn(); //Phillip
		void checkVictory();

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
		int actionsLeft;
		// Stores whether or not there has been a victory and which team has won.
		int victory;
};
