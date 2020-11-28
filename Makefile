#[target] : [dependencies]
#	commands

game : game.cpp TicTacToe.cpp
	g++ -o $@ $^
	./game