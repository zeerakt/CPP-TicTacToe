#include "Intermediate.h"
#include <iostream>
using namespace std;
Intermediate::Intermediate()
{
	cout << "This is the intermediate stage\nI may not be expert, but i ain't easy, either, DOOFUS\n" << endl;
}
void Intermediate::computer_move(){
	int square;
	int row, col;

	/* Use first strategy rule that returns valid square */
	square = tic_tac_toe::find_win(computer);
	if (!square)
		square = tic_tac_toe::find_win(user);
	if (!square)
		square = tic_tac_toe::find_corner();
	if (!square)
		square = tic_tac_toe::find_side();

	printf("\nI am choosing square %d!\n", square);

	row = (square - 1) / 3;
	col = (square - 1) % 3;

	board[row][col] = computer;

	return;
}

Intermediate::~Intermediate()
{
}
