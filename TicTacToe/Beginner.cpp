#include "Beginner.h"
#include <iostream>
using namespace std;

Beginner::Beginner()
{
	cout <<endl<< "This is the beginner stage\nPlease go EASY on me. I am just a beginner :(" << endl;
}
void Beginner::computer_move(){
	int square;
	int row, col;

	/* Use first strategy rule that returns valid square */
	square = tic_tac_toe::find_win(computer);
	if (!square)
		square = tic_tac_toe::find_win(user);
	if (!square)
		square = tic_tac_toe::find_side();

	printf("\nI am choosing square %d!\n", square);

	row = (square - 1) / 3;
	col = (square - 1) % 3;

	board[row][col] = computer;

	return;
}


Beginner::~Beginner()
{
}
