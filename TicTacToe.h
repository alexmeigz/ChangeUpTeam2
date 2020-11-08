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
		std::deque<int>[3][3] field; // index 0 is bottom; index 2 is top
		int teamSide; // 1 is blue; -1 is red; 0 is none
		int actionLeft;
};
