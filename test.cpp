#include "TicTacToe.h"
#include <iostream>
using namespace std;



int main(){
    TicTacToe gameBoard;
    cout << gameBoard.checkVictoryHorizontal(-1) << endl;
    return 0;
}
