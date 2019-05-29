#include "tic_tac_toe.h"
#include <iostream>
//Shows sample board to user
void  tic_tac_toe::sample_board(void){
	printf("\n");

	printf("   *   *   \n");
	printf(" 1 * 2 * 3 \n");
	printf("   *   *   \n");
	printf("***********\n");
	printf("   *   *   \n");
	printf(" 4 * 5 * 6 \n");
	printf("   *   *   \n");
	printf("***********\n");
	printf("   *   *   \n");
	printf(" 7 * 8 * 9 \n");
	printf("   *   *   \n");
	printf("\n");
}
// Make sure board starts off empty.
void  tic_tac_toe::init_board(void)
{
	int row, col;

	for (row = 0; row < 3; row++)
	for (col = 0; col < 3; col++)
		board[row][col] = ' ';

	return;
}
int  tic_tac_toe::user_first(void)
{
	char response;

	printf("Do you want to go first? (y/n) ");
	do
	{
		response = getchar();
	} while ((response != 'y') && (response != 'Y') &&
		(response != 'n') && (response != 'N'));

	if ((response == 'y') || (response == 'Y'))
		return 1;
	else
		return 0;
}
void tic_tac_toe::play_game(void)
{
	int turn;

	for (turn = 1; turn <= 9; turn++)
	{
		/* Check if turn is even or odd to determine which player should move. */
		if (turn % 2 == 1)
		{
			if (computer == 'X')
				this->computer_move();
			else
				this->player_move();
		}
		else
		{
			if (computer == 'O')
				this->computer_move();
			else
				tic_tac_toe::player_move();
		}

		tic_tac_toe::draw_board();

		if (tic_tac_toe::symbol_won(computer)) {
			printf("\nI WIN!!!\n\n");
			return;
		}
		else if (tic_tac_toe::symbol_won(user)) {
			printf("\nCongratulations, you win!\n\n");
			return;
		}
	}

	printf("\nThe game is a draw.\n\n");
	return;
}
/*int tic_tac_toe::play_again(void)
{
	char response;

	printf("Do you want to play again? (y/n) ");
		if ((response == 'y') || (response == 'Y'))
		return 1;
	else
		return 0;
}*/
void tic_tac_toe::instructions(void){
	printf("The game is played on a grid that's 3 squares by 3 squares.\n");
	printf("The sample board is shown below:\n");
	tic_tac_toe::sample_board();
	printf("You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares.\n");
	printf("The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
	printf("When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\nGood Luck! :)");
	return;
}
void tic_tac_toe::computer_move(void)
{
	int square;
	int row, col;

	/* Use first strategy rule that returns valid square */
	square = tic_tac_toe::find_win(computer);
	if (!square)
		square = tic_tac_toe::find_win(user);
	if (!square)
		square = tic_tac_toe::middle_open();
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
/*
* Find a win, if any, for the given symbol.
* If a winning square exists, return the square;
* Otherwise, return 0;
*/
int tic_tac_toe::find_win(char symbol)
{
	int square, row, col;
	int result = 0;

	/*
	* Loop through the 9 squares.
	* For each, if it is empty, fill it in with the given symbol and check
	* if this has resulted in a win.  If so, keep track of this square in result.
	* Either way, reset the square to empty afterwards.  After the loop, if one or
	* more wins have been found, the last will be recorded in result.
	* Otherwise, result will still be 0.
	*/
	for (square = 1; square <= 9; square++)
	{
		row = (square - 1) / 3;
		col = (square - 1) % 3;

		if (board[row][col] == ' ')
		{
			board[row][col] = symbol;
			if (tic_tac_toe::symbol_won(symbol))
				result = square;
			board[row][col] = ' ';
		}
	}

	return result;
}

/* If middle square is empty, return 5; Otherwise return 0. */
int tic_tac_toe::middle_open(void)
{	
	if (board[1][1] == ' ')
		return 5;
	else
		return 0;
}
/* Return the number of an empty corner, if one exists; Otherwise return 0. */
int tic_tac_toe::find_corner(void)
{
	if (board[0][0] == ' ')
		return 1;
	if (board[0][2] == ' ')
		return 3;
	if (board[2][0] == ' ')
		return 7;
	if (board[2][2] == ' ')
		return 9;

	return 0;
}

/* Return the number of an empty side square, if one exists; Otherwise return 0. */
int tic_tac_toe::find_side(void)
{
	if (board[0][1] == ' ')
		return 2;
	if (board[1][0] == ' ')
		return 4;
	if (board[1][2] == ' ')
		return 6;
	if (board[2][1] == ' ')
		return 8;

	return 0;
}
void tic_tac_toe::player_move(void)
{
	int square;
	int row, col;

	do
	{
		printf("Enter a square: ");
		scanf_s("%d", &square);
	} while (!tic_tac_toe::square_valid(square));

	row = (square - 1) / 3;
	col = (square - 1) % 3;

	board[row][col] = user;

	return;
}

/* Check if the given square is valid and empty. */
int tic_tac_toe::square_valid(int square)
{
	int row, col;

	row = (square - 1) / 3;
	col = (square - 1) % 3;

	if ((square >= 1) && (square <= 9))
	{
		if (board[row][col] == ' ')
			return 1;
	}

	return 0;
}
int tic_tac_toe::symbol_won(char symbol)
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		if ((board[row][0] == symbol) && (board[row][1] == symbol) && (board[row][2] == symbol))
			return 1;
	}

	for (col = 0; col < 3; col++)
	{
		if ((board[0][col] == symbol) && (board[1][col] == symbol) && (board[2][col] == symbol))
			return 1;
	}

	if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol))
		return 1;

	if ((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol))
		return 1;

	return 0;
}
void tic_tac_toe::draw_board(void)
{
	int row, col;

	printf("\n");
	for (row = 0; row < 3; row++)
	{
		printf("   *   *   \n");
		printf(" %c * %c * %c \n", board[row][0], board[row][1], board[row][2]);
		printf("   *   *   \n");
		if (row != 2)
			printf("***********\n");
	}
	printf("\n");

	return;
}