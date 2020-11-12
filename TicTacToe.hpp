#include <deque>

// Alliance Convention:
// * 1 is the blue alliance
// * -1 is the red alliance
// * 0 is for no alliance
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
		int getVictory(); // Erin

	private:
		// These functions should only be called from within this class.
		void changeTurn(); //Phillip
		void checkVictory();
		// Below three functions will be called within checkVictory(); take teamID as parameter to count score for that team; return socre.
		int checkVictoryHorizontal(int teamSide); // (Sean) check all (18) horizontal rows; 9 for left to right, 9 for front to back.
		int checkVictoryVertical(int teamSide); // (Shivani) check all (9) vertical rows; 9 for bottom to top.
		int checkVictoryDiagonal(int teamSide); // check all (22) diagonal rows; 6 6 6 4 (I don't know how to describe them with words).

		// Stores the state of the game board
		// * For each deque<int>, index 0 is the bottom and index 2 is top of each stack.
		// * For the entire field, [0][0] is bottom left and [2][2] is top right.
		std::deque<int> field[3][3];

		// Flag determining whose turn it is:
		int teamSide;

		// Decrementing counter for keeping track of how many actions are left in the player's turn.
		int actionsLeft;

		// Stores whether or not there has been a victory and which team has won.
		int victory;
};
