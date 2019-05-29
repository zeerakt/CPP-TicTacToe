#pragma once
class tic_tac_toe
{
private:


public:
	void sample_board(void);
	void init_board(void);
	void draw_board(void);
	int user_first(void);
	void play_game(void);
	int play_again(void);
	virtual void computer_move(void);
	void player_move(void);
	virtual int find_win(char);
	int middle_open(void);
	int find_corner(void);
	int find_side(void);
	int symbol_won(char);
	int square_valid(int);
	void instructions(void);
	char board[3][3];
	char computer, user;
};